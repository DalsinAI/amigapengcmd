Penguin Command 1.6.11 for AmigaOS 3.x
======================================

Penguin Command (Karl Bartel), the missile defence game after Missile
Command: missiles and bombs rain down on your six domed cities, and your
three cannons shoot them down where you aim. Normal and arcade games,
ScreamTracker music. For AmigaOS 3.x on a 68040 or 68060 with an FPU and
an RTG screen, on OpenGPU's SDL 1.2 (sdl12-compat).

Base: penguin-command_1.6.11.orig.tar.gz from Debian (sha256
659c7b5f3f968f386e820cf7387d88c0a61c17dfbdb005bd85f8e93c537e89d6), with
Debian's patches (1.6.11-4.1) as the second commit. Branch
team2/pengcmd-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the title screen and its menu, Normal Game (the missiles falling,
the cannons firing at the crosshair, the explosions, cities hit), Escape
back to the title, and Quit back to the Shell, the settings and high
scores written to penguin-command.dat; the game reported 90 frames a
second. The music and sounds load without an error; the lab is muted, so
they were not heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later (LIBS:OpenGPU/SDL2.module). Everything else is
  in the program.


How to play
-----------

Open the PenguinCommand icon, or run PenguinCommand from a Shell. It
opens an 800x600 window (PenguinCommand -f for the full screen, -s for no
sound). Click a word on the title screen to choose. In the game the mouse
aims; the left, middle and right buttons (or A, S and D) fire the left,
middle and right cannons. P pauses, Escape ends the game. ReadMe-upstream
in the drawer is upstream's README. The pictures, sounds and music are in
the drawer's data/; the high scores and settings are penguin-command.dat
in the drawer.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers, the OpenGPU kit and
the Team's static libpng, libjpeg and zlib (see the Makefile's head). The
drawer is dist/PenguinCommand (and dist/PenguinCommand.info).


What was changed
----------------

- src/main.c: on AmigaOS the game starts in a window (-f for the full
  screen; upstream starts full screen).
- src/options.c: the settings and high scores are
  PROGDIR:penguin-command.dat; the file is closed before it is written
  again (AmigaDOS will not open a file for writing while it is open for
  reading, so the game quit at its first start).
- amiga/Makefile.amigaos builds src/Makefile.am's sources with
  configure's -DUSE_SOUND and -DJOYSTICK; the data is PROGDIR:data.
- No SDL_image or SDL_mixer 1.2 for OpenGPU's SDL 1.2: the Team's
  amiga/sdl_image_lite.c (PNG on libpng, now JPEG on libjpeg too, for the
  title and background pictures) and amiga/sdl_mixer_lite.c (WAV, with
  libmikmod 3.3.16 for the music: amiga/libmikmod, its player, S3M loader
  and no-sound driver, at most 16 voices), from the Critical Mass port.
- amiga/stack.c: 256 KB of stack.


Licences
--------

Penguin Command, its pictures, sounds and music: GPL 2 or later
(COPYING.txt). libmikmod: LGPL 2 or later (COPYING-libmikmod.txt). The
Amiga files (amiga/): the AmiCradle Team, GPL 2 or later, except the
mixer, which comes from the Team's Wizznic port and is GPL 3 or later, so
the program as built here is GPL 3 or later; the icons are our
own GlowIcons (amiga/icons/art/pengcmd.svg).
