/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like Penguin Command. */
unsigned long __stack = 256 * 1024;
static const char version[] __attribute__((used)) = "$VER: Penguin Command 1.6.11 Amiga (06.11.2026)";
