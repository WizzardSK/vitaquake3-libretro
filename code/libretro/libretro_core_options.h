#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include "../libretro-common/include/libretro.h"
#include "../libretro-common/include/retro_inline.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 */

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */

struct retro_core_option_v2_category option_cats_us[] = {
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_us[] = {
   {
      "vitaquakeiii_framerate",
      "Framerate (restart)",
      NULL,
      "Modify framerate. Requires a restart.",
      NULL,
      NULL,
      {
         { "auto",            "Auto"},
         { "50",              "50fps"},
         { "60",              "60fps"},
         { "72",              "72fps"},
         { "75",              "75fps"},
         { "90",              "90fps"},
         { "100",              "100fps"},
         { "119",              "119fps"},
         { "120",              "120fps"},
         { "144",              "144fps"},
         { "155",              "155fps"},
         { "160",              "160fps"},
         { "165",              "165fps"},
         { "180",              "180fps"},
         { "200",              "200fps"},
         { "240",              "240fps"},
         { "244",              "244fps"},
         { "300",              "300fps"},
         { "360",              "360fps"},
         { NULL, NULL },
      },
      "auto"
   },
   {
      "vitaquakeiii_audio_samplerate",
      "Sound Samplerate (Hint) (restart)",
      NULL,
      "Audio output rate. 'Auto' matches the frontend's target rate, which avoids the frontend resampler's extra filtering and group delay; that rate-matching, not a higher number, is what helps latency. Higher fixed rates give the music-stream resampler finer time resolution, but do little for Quake's own low-rate sound effects. Falls back to 48 kHz when the frontend can't report a target rate. Requires a restart.",
      NULL,
      NULL,
      {
         { "auto",  "Auto" },
         { "32000", "32 kHz" },
         { "44100", "44 kHz" },
         { "48000", "48 kHz" },
         { "96000", "96 kHz" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "vitaquakeiii_resolution",
      "Internal resolution (restart)",
      NULL,
      "Configure the resolution. Requires a restart.",
      NULL,
      NULL,
      {
         { "480x272",   NULL },
         { "640x368",   NULL },
         { "640x480",   NULL },
         { "720x408",   NULL },
         { "856x480",   NULL },
         { "800x600",   NULL },
         { "960x544",   NULL },
         { "1024x768",   NULL },
         { "1152x864",   NULL },
         { "1280x720",   NULL },
         { "1280x960",   NULL },
         { "1400x1050",   NULL },
         { "1600x1200",   NULL },
         { "1920x1080",   NULL },
         { "2048x1536",   NULL },
         { "2560x1440",   NULL },
         { "3840x2160",   NULL },
         { NULL, NULL },
      },
      "960x544"
   },
   {
      "vitaquakeiii_overbrights",
      "Overbrights",
      NULL,
      "Increases the range of lighting while comprimising color precision. Requires a restart.",
      NULL,
      NULL,
      {
         { "disabled",  "Disabled" },
         { "enabled",   "Enabled" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "vitaquakeiii_wide",
      "Widescreen",
      NULL,
      "",
      NULL,
      NULL,
      {
         { "disabled",  "Vert-" },
         { "enabled",   "Hor+" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "vitaquakeiii_invert_y_axis",
      "Invert Y Axis",
      NULL,
      "Invert the gamepad right analog stick's Y axis.",
      NULL,
      NULL,
      {
         { "disabled",  "Disabled" },
         { "enabled",   "Enabled" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "vitaquakeiii_strict_paks",
      "Strict Pak Checking",
      NULL,
      "Disabled (default): allow partial or CD installs (e.g. only pak0-pak6) to boot. Some content may be missing or incorrect, and online play against pure servers may be refused. Enabled: require a complete, checksum-verified id pak set (pak0-pak8, the 1.32 point release). pak0.pk3 is always required.",
      NULL,
      NULL,
      {
         { "disabled",  "Disabled" },
         { "enabled",   "Enabled" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "vitaquakeiii_pickups",
      "2D Pickups Rendering",
      NULL,
      "Makes pickups (medkits, weapons, quad damage, etc.) be rendered with 2D icons.",
      NULL,
      NULL,
      {
         { "disabled",  "Disabled" },
         { "enabled",   "Enabled" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "vitaquakeiii_weapon",
      "Show Equipped Weapon",
      NULL,
      "Shows equipped weapon on screen.",
      NULL,
      NULL,
      {
         { "disabled",  "Disabled" },
         { "enabled",   "Enabled" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "vitaquakeiii_shadows",
      "Shadows Quality",
      NULL,
      "Configure the quality of shadows rendering.",
      NULL,
      NULL,
      {
         { "disabled",  "Disabled" },
         { "low",       "Low" },
         { "high",      "High" },
         { NULL, NULL },
      },
      "low"
   },
   {
      "vitaquakeiii_filter",
      "Textures Filter",
      NULL,
      "Configure the textures filter to use.",
      NULL,
      NULL,
      {
         { "disabled",  "Disabled" },
         { "linear",    "Linear" },
         { "bilinear",  "Bilinear" },
         { "trilinear",  "Trilinear" },
         { NULL, NULL },
      },
      "bilinear"
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_us = {
   option_cats_us,
   option_defs_us
};

/* RETRO_LANGUAGE_ITALIAN */
struct retro_core_option_v2_definition option_defs_it[] = {
   {
      "vitaquakeiii_framerate",
      "Framerate (riavvio)",
      NULL,
      "Modifica il framerate. Richiede un riavvio.",
      NULL,
      NULL,
      {
         { "auto",            "Auto"},
         { "50",              "50fps"},
         { "60",              "60fps"},
         { "72",              "72fps"},
         { "75",              "75fps"},
         { "90",              "90fps"},
         { "100",              "100fps"},
         { "119",              "119fps"},
         { "120",              "120fps"},
         { "144",              "144fps"},
         { "155",              "155fps"},
         { "160",              "160fps"},
         { "165",              "165fps"},
         { "180",              "180fps"},
         { "200",              "200fps"},
         { "240",              "240fps"},
         { "244",              "244fps"},
         { NULL, NULL },
      },
      "auto"
   },
   {
      "vitaquakeiii_audio_samplerate",
      "Frequenza audio (suggerimento) (riavvio)",
      NULL,
      "Frequenza di uscita audio. 'Auto' corrisponde alla frequenza richiesta dal frontend, riducendo latenza e filtraggio del ricampionatore. Frequenze fisse piu alte offrono maggiore risoluzione al ricampionatore della musica, ma poco per gli effetti sonori di Quake. Ripiega su 48 kHz se il frontend non indica una frequenza. Richiede un riavvio.",
      NULL,
      NULL,
      {
         { "auto",  "Auto" },
         { "32000", "32 kHz" },
         { "44100", "44 kHz" },
         { "48000", "48 kHz" },
         { "96000", "96 kHz" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "vitaquakeiii_resolution",
      "Risoluzione interna (riavvio)",
      NULL,
      "Configura la risoluzione. Richiede un riavvio.",
      NULL,
      NULL,
      {
         { "480x272",   NULL },
         { "640x368",   NULL },
         { "720x408",   NULL },
         { "960x544",   NULL },
         { "1280x720",   NULL },
         { "1920x1080",   NULL },
         { "2560x1440",   NULL },
         { "3840x2160",   NULL },
         { NULL, NULL },
      },
      "960x544"
   },
   {
      "vitaquakeiii_invert_y_axis",
      "Inverti Asse Y",
      NULL,
      "Inverte l'asse Y dell'analogico destro.",
      NULL,
      NULL,
      {
         { "disabled",  "Disattivato" },
         { "enabled",   "Attivato" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "vitaquakeiii_pickups",
      "Rendering 2D Pickup",
      NULL,
      "Rende i pickup (medkit, armi, danno quadruplo, ecc.) renderizzati con icone 2D.",
      NULL,
      NULL,
      {
         { "disabled",  "Disattivato" },
         { "enabled",   "Attivato" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "vitaquakeiii_weapon",
      "Mostra Arma Equipaggiata",
      NULL,
      "Mostra l'arma equipaggiata su schermo.",
      NULL,
      NULL,
      {
         { "disabled",  "Disattivato" },
         { "enabled",   "Attivato" },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "vitaquakeiii_shadows",
      "Qualità Ombre",
      NULL,
      "Configura la qualità del rendering delle ombre.",
      NULL,
      NULL,
      {
         { "disabled",  "Disattivate" },
         { "low",       "Bassa" },
         { "high",      "Alta" },
         { NULL, NULL },
      },
      "low"
   },
   {
      "vitaquakeiii_filter",
      "Filtro Texture",
      NULL,
      "Configura il filtro delle texture da utilizzare.",
      NULL,
      NULL,
      {
         { "disabled",  "Disattivato" },
         { "linear",    "Lineare" },
         { "bilinear",  "Bilineare" },
         { "trilinear",  "Trilineare" },
         { NULL, NULL },
      },
      "bilinear"
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_it = {
   option_cats_us,
   option_defs_it
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

struct retro_core_options_v2 *options_intl[RETRO_LANGUAGE_LAST] = {
   &options_us, /* RETRO_LANGUAGE_ENGLISH */
   NULL,        /* RETRO_LANGUAGE_JAPANESE */
   NULL,        /* RETRO_LANGUAGE_FRENCH */
   NULL,        /* RETRO_LANGUAGE_SPANISH */
   NULL,        /* RETRO_LANGUAGE_GERMAN */
   &options_it, /* RETRO_LANGUAGE_ITALIAN */
   NULL,        /* RETRO_LANGUAGE_DUTCH */
   NULL,        /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   NULL,        /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   NULL,        /* RETRO_LANGUAGE_RUSSIAN */
   NULL,        /* RETRO_LANGUAGE_KOREAN */
   NULL,        /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   NULL,        /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   NULL,        /* RETRO_LANGUAGE_ESPERANTO */
   NULL,        /* RETRO_LANGUAGE_POLISH */
   NULL,        /* RETRO_LANGUAGE_VIETNAMESE */
   NULL,        /* RETRO_LANGUAGE_ARABIC */
   NULL,        /* RETRO_LANGUAGE_GREEK */
   NULL,        /* RETRO_LANGUAGE_TURKISH */
};

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb,
      bool *categories_supported)
{
   unsigned version  = 0;
   unsigned language = 0;

   if (!environ_cb || !categories_supported)
      return;

   *categories_supported = false;

   if (!environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version))
      version = 0;

   if (version >= 2)
   {
      struct retro_core_options_v2_intl core_options_intl;

      core_options_intl.us    = &options_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = options_intl[language];

      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL,
            &core_options_intl);
   }
   else
   {
      size_t i, j;
      size_t option_index              = 0;
      size_t num_options               = 0;
      struct retro_core_option_definition
            *option_v1_defs_us         = NULL;
      size_t num_options_intl          = 0;
      struct retro_core_option_v2_definition
            *option_defs_intl          = NULL;
      struct retro_core_option_definition
            *option_v1_defs_intl       = NULL;
      struct retro_core_options_intl
            core_options_v1_intl;
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine total number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      if (version >= 1)
      {
         /* Allocate US array */
         option_v1_defs_us = (struct retro_core_option_definition *)
               calloc(num_options + 1, sizeof(struct retro_core_option_definition));

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            struct retro_core_option_v2_definition *option_def_us = &option_defs_us[i];
            struct retro_core_option_value *option_values         = option_def_us->values;
            struct retro_core_option_definition *option_v1_def_us = &option_v1_defs_us[i];
            struct retro_core_option_value *option_v1_values      = option_v1_def_us->values;

            option_v1_def_us->key           = option_def_us->key;
            option_v1_def_us->desc          = option_def_us->desc;
            option_v1_def_us->info          = option_def_us->info;
            option_v1_def_us->default_value = option_def_us->default_value;

            /* Values must be copied individually... */
            while (option_values->value)
            {
               option_v1_values->value = option_values->value;
               option_v1_values->label = option_values->label;

               option_values++;
               option_v1_values++;
            }
         }

         if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
             (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH) &&
             options_intl[language])
            option_defs_intl = options_intl[language]->definitions;

         if (option_defs_intl)
         {
            /* Determine number of intl options */
            while (true)
            {
               if (option_defs_intl[num_options_intl].key)
                  num_options_intl++;
               else
                  break;
            }

            /* Allocate intl array */
            option_v1_defs_intl = (struct retro_core_option_definition *)
                  calloc(num_options_intl + 1, sizeof(struct retro_core_option_definition));

            /* Copy parameters from option_defs_intl array */
            for (i = 0; i < num_options_intl; i++)
            {
               struct retro_core_option_v2_definition *option_def_intl = &option_defs_intl[i];
               struct retro_core_option_value *option_values           = option_def_intl->values;
               struct retro_core_option_definition *option_v1_def_intl = &option_v1_defs_intl[i];
               struct retro_core_option_value *option_v1_values        = option_v1_def_intl->values;

               option_v1_def_intl->key           = option_def_intl->key;
               option_v1_def_intl->desc          = option_def_intl->desc;
               option_v1_def_intl->info          = option_def_intl->info;
               option_v1_def_intl->default_value = option_def_intl->default_value;

               /* Values must be copied individually... */
               while (option_values->value)
               {
                  option_v1_values->value = option_values->value;
                  option_v1_values->label = option_values->label;

                  option_values++;
                  option_v1_values++;
               }
            }
         }

         core_options_v1_intl.us    = option_v1_defs_us;
         core_options_v1_intl.local = option_v1_defs_intl;

         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_v1_intl);
      }
      else
      {
         /* Allocate arrays */
         variables  = (struct retro_variable *)calloc(num_options + 1,
               sizeof(struct retro_variable));
         values_buf = (char **)calloc(num_options, sizeof(char *));

         if (!variables || !values_buf)
            goto error;

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            const char *key                        = option_defs_us[i].key;
            const char *desc                       = option_defs_us[i].desc;
            const char *default_value              = option_defs_us[i].default_value;
            struct retro_core_option_value *values = option_defs_us[i].values;
            size_t buf_len                         = 3;
            size_t default_index                   = 0;

            values_buf[i] = NULL;

            if (desc)
            {
               size_t num_values = 0;

               /* Determine number of values */
               while (true)
               {
                  if (values[num_values].value)
                  {
                     /* Check if this is the default value */
                     if (default_value)
                        if (strcmp(values[num_values].value, default_value) == 0)
                           default_index = num_values;

                     buf_len += strlen(values[num_values].value);
                     num_values++;
                  }
                  else
                     break;
               }

               /* Build values string */
               if (num_values > 0)
               {
                  buf_len += num_values - 1;
                  buf_len += strlen(desc);

                  values_buf[i] = (char *)calloc(buf_len, sizeof(char));
                  if (!values_buf[i])
                     goto error;

                  strcpy(values_buf[i], desc);
                  strcat(values_buf[i], "; ");

                  /* Default value goes first */
                  strcat(values_buf[i], values[default_index].value);

                  /* Add remaining values */
                  for (j = 0; j < num_values; j++)
                  {
                     if (j != default_index)
                     {
                        strcat(values_buf[i], "|");
                        strcat(values_buf[i], values[j].value);
                     }
                  }
               }
            }

            variables[option_index].key   = key;
            variables[option_index].value = values_buf[i];
            option_index++;
         }

         /* Set variables */
         environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);
      }

error:
      /* Clean up */

      if (option_v1_defs_us)
      {
         free(option_v1_defs_us);
         option_v1_defs_us = NULL;
      }

      if (option_v1_defs_intl)
      {
         free(option_v1_defs_intl);
         option_v1_defs_intl = NULL;
      }

      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
