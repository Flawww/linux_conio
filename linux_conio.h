#include <string>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>
#include <signal.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#endif

// sets up sigaction handler for linux, so we can reset terminal settings from conio-mode
// if the process recieves a SIGTERM/SIGINT/SIGTSTP/SIGQUIT - disable conio mode
void setup_signal_interceptor();

// disables conio mode (for _getch() and _kbhit()) on Linux
void disable_conio_mode();

// enables conio mode (for _getch() and _kbhit()) on Linux
void enable_conio_mode();

// non-blocking version of getch which works for both Windows and Linux
// if no character could be read, EOF is returned.
int getch_noblock();

#ifndef _WIN32
// Linux-implementation of non-blocking getch (requires conio mode to be non-blocking)
int _getch();

// Linux-implementation of kbhit (requires conio mode to be enabled)
bool _kbhit();
#endif