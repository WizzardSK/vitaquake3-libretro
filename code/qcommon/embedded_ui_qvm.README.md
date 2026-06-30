# embedded_ui_qvm.h

`embedded_ui_qvm.h` contains a baseq3 `ui.qvm` baked into the core, stored
**zlib-compressed** to keep the binary small (~92 KB compressed vs ~302 KB
raw). `vm.c` inflates it once at load via the engine's zlib (`VM_ArmEmbeddedUI`).
It is the stock-format (vq3) Quake III `q3_ui` bytecode with these changes for the
libretro core:

- the **"Fullscreen:"** item removed from the *System > Graphics* menu (the core
  always renders fullscreen into the frontend's framebuffer);
- the **"Voodoo"** entry removed from the **GL Driver** list (no 3dfx/glide path
  exists in a modern GL core), leaving only "Default";
- the **"Color Depth:"** (r_colorbits) and **"Texture Quality:"** (r_texturebits)
  items removed from *System > Graphics* — both drive cvars that no longer exist
  in this 32-bit-only core ("Texture Detail:" / r_picmip is kept); and
- the **"Sound System:"** (SDL/OpenAL) selector and the **"SDL Sound Quality:"**
  control removed from the *System > Sound* menu (the engine has a single base
  sound backend; OpenAL was removed from the core).

At runtime the engine uses this embedded copy for the `ui` VM **unless** a loose
`baseq3/vm/ui.qvm` is present in a real game directory on disk, in which case
that file overrides the embedded copy (see `VM_Create` / `VM_Restart` in
`vm.c`, gated by `FS_LooseFileExists`).

## Regenerating the header

The QVM itself is built from the standard `q3_ui` sources with the
`ui_video.c` change below, using the ioquake3 QVM toolchain
(`q3lcc`/`q3cpp`/`q3rcc`/`q3asm`, built from ioquake3 `code/tools`):

1. Compile each `q3_ui/*.c` (plus `game/bg_misc.c`, `game/bg_lib.c`,
   `qcommon/q_math.c`, `qcommon/q_shared.c`) with `q3lcc -DUI` to `.asm`.
2. Link with `q3asm -vq3` together with `ui/ui_syscalls.asm` into `ui.qvm`.
   The `-vq3` flag selects the 1.32b-compatible format (magic `0x12721444`).

The `ui_video.c` change: remove the `ID_FULLSCREEN` spincontrol setup and its
`Menu_AddItem`, and pin `s_graphicsoptions.fs.curvalue = 1` (the dependent
resolution/driver logic reads this field, so it must read as "fullscreen on").

Then turn the resulting `ui.qvm` into this header:

```sh
python3 embedded_ui_qvm_gen.py path/to/ui.qvm > embedded_ui_qvm.h
```
