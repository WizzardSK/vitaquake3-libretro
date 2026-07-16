# vitaquake3 (libretro)

```
,---------------------------------------.
|   _                     _       ____  |
|  (_)___  __ _ _  _ __ _| |_____|__ /  |
|  | / _ \/ _` | || / _` | / / -_)|_ \  |
|  |_\___/\__, |\_,_\__,_|_\_\___|___/  |
|            |_|                        |
`---------------------------------------'
```

A libretro core wrapping **vitaQuakeIII**, ioquake3 port, exposed
through the libretro API. It runs Quake III: Arena and several games and mods
built on the same engine, rendered through the frontend's OpenGL context.

The core identifies itself as `vitaQuakeIII` and loads `.pk3` content directly
from disk (`need_fullpath`), so game data is read from the folder the loaded pak
lives in rather than being extracted by the frontend.

## Supported games

The active game is selected automatically from the path of the `.pk3` you load —
no separate cores, no command-line editing. The path is matched case-insensitively:

| Detected in path | Game                     | `fs_game` | Mode       |
|------------------|--------------------------|-----------|------------|
| *(default)*      | Quake III: Arena         | `baseq3`  | id data    |
| `missionpack`    | Quake III: Team Arena    | `missionpack` | id data |
| `q3ut4`          | Urban Terror             | `q3ut4`   | mod        |
| `baseoa`         | OpenArena                | `baseoa`  | standalone |
| `baseq3r`        | Q3 Rally                 | `baseq3r` | standalone |

Load any `.pk3` inside the corresponding game directory (for example
`baseq3/pak0.pk3`) and the core boots that game. Quake III: Arena and Team Arena
require the retail id Software pak set; OpenArena and Q3 Rally ship their own free
data and run standalone.

## Rendering

The core drives the classic GL1 renderer over the frontend's hardware GL context
(via libretro's GL state manager), so it inherits the frontend's window, vsync and
display path. Notable options exposed to the frontend:

- **Internal resolution** — from `480x272` up to `3840x2160` (default `960x544`).
  Higher than any native Q3 client thanks to the resolution-independent HUD/menu paths.
- **Widescreen** — `Hor+` (expand field of view, default) or `Vert-` (crop).
  Aspect ratio is reported to the frontend as 16:9 when enabled, otherwise
  derived from the internal resolution.
- **Overbrights** — wider lighting range at the cost of some colour precision (default on).
- **Shadows quality** — Disabled / Low / High (default Low).
- **Texture filter** — Disabled / Linear / Bilinear / Trilinear (default Bilinear).
- **2D pickups rendering** — draw medkits, weapons, powerups etc. as flat 2D icons (default off).
- **Show equipped weapon** — draw the first-person weapon model (default on).

Resolution, framerate and overbrights changes are latched and take effect on core
restart; the rest apply live.

## Framerate

**Framerate** can be pinned to a fixed value from 50 up to 360 fps, or left on
**Auto**, which queries the frontend's target refresh rate (falling back to 60 fps
if the frontend can't report one). The engine advances on a deterministic integer
frame clock — one fixed time quantum per frame with a millisecond remainder carry —
so the long-run rate matches the requested fps exactly, with no floating-point
drift and no dependence on a host wall clock. Changing the framerate requires a
core restart.

## Audio

Output is 16-bit by default, with per-game float batch output negotiated
automatically when the frontend supports it.

The **Sound Samplerate (Hint)** option selects the output rate:

- **Auto** (default) matches the frontend's target sample rate. Rate-matching the
  frontend — not simply picking a bigger number — is what avoids the extra
  resampling, filtering and group delay a mismatch would introduce. Falls back to
  48 kHz if the frontend doesn't report a target rate.
- **32 / 44 / 48 / 96 kHz** are taken verbatim. Higher fixed rates give the
  music-stream resampler finer time resolution but do little for Quake's own
  low-rate sound effects.

Changing the samplerate requires a core restart.

## Input

Assign a controller type per port from the frontend's Controls menu. Four device
types are provided:

- **Gamepad Classic** — single-stick digital layout (movement + strafe, jump/fire
  on triggers, weapon cycling on shoulders).
- **Gamepad Classic Alt** — variant of the above with look bound to the face
  buttons and a run toggle.
- **Gamepad Modern** — twin-stick. Left stick moves, right stick looks (fed as
  relative mouse motion, 15% deadzone). This is the layout most players will want.
- **RetroKeyboard + Mouse** — full keyboard passthrough plus relative mouse look;
  left/right mouse buttons map to attack/altfire and the wheel to weapon
  next/previous. Native mouselook and console access, closest to the desktop Q3
  experience.

The right-stick / mouse look axis can be inverted with the **Invert Y Axis**
option (default on).

## Pak checking

**Strict Pak Checking** controls how strict the core is about game data:

- **Disabled** (default) — permissive. Partial or CD installs (e.g. only
  `pak0`–`pak6`) will still boot, so you can play with whatever data you have.
  Some content may be missing or incorrect, and pure online servers may refuse
  the connection. `pak0.pk3` is always required.
- **Enabled** — require the complete, checksum-verified id pak set (`pak0`–`pak8`,
  the 1.32 point release).

The setting is applied at startup, before the engine's pak-integrity gate runs.

## Localization

Core option labels and descriptions are available in **English** and **Italian**;
other frontend languages fall back to English.

## Not supported

- **Save states** and rewind — the engine holds too much live state to snapshot;
  `retro_serialize_size` reports 0.
- **SRAM / memory mapping** — no cartridge-style memory is exposed. In-game
  settings and mod data persist normally through the engine's own config/write path.
- **Rumble.**

## Building

The core builds with the standard libretro Makefile. Pick a target with the
`platform=` variable:

```
make platform=unix      # Linux (.so)
make platform=osx       # macOS (.dylib)
make platform=win       # Windows (.dll)
make platform=ios       # iOS
make platform=libnx     # Nintendo Switch
make platform=vita      # PS Vita
make platform=emscripten
```

Omitting `platform=` auto-detects the host (Linux/macOS/Windows). The core links
against the frontend's OpenGL context, so a GL-capable libretro frontend is
required at runtime.

## Content setup

1. Create a game directory (`baseq3`, `baseoa`, etc.) and place its `.pk3` files inside.
2. For Quake III: Arena / Team Arena, copy the retail id paks (`pak0.pk3` … `pak8.pk3`)
   into `baseq3` (and `missionpack` for Team Arena).
3. Load any `.pk3` from the target game directory in your frontend.

Data is read from the directory the loaded pak sits in; the core does not ship
game assets.

## Credits & licensing

vitaQuakeIII is by Rinnegatamante, built on ioquake3, which derives from id
Software's Quake III: Arena GPL source release. The core and all bundled engine
sources are distributed under the **GPL-2.0** license; see `COPYING.txt`. Retail
Quake III game data is not included and must be supplied by the user. OpenArena
and Q3 Rally provide their own freely distributable data.
