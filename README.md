# Linux implementation of <conio.h>
This project implements the Windows-specific functions `_getch()` and `_kbhit()` from `conio.h`. These functions are used to read characters from stdin, without the user having to press *enter*, with the option to do it in a non-blocking way, which can be used to detect keypresses without having to "pause" the application while waiting for input.

## Cross platform
Despite being an implementation of a Windows API for Linux, this project also works for Windows. The only function which is "implemented" for Windows (ie. adds onto the already existing functionality) is:
```c++
int getch_noblock(); 
```
which is a non-blocking version of `_getch()`, which returns EOF if no character can be read from stdin.

# Usage
* Add the `linux_conio.h` and `linux_conio.cpp` files to your project
* Include the `linux_conio.h` header file in your project
* Call `enable_conio_mode()` every time before the library is used (if *conio mode* is currently disabled)
* Use `_getch()`, `_kbhit()` and/or `getch_noblock()` as you would normally 
* Call `disable_conio_mode()` when your program is closing to restore the console settings.

# Compiling
This project compiles on any modern C++ compiler for either Linux or Windows. In this example I will use `gcc`
To compile the project and run the test cases, run:
```
g++ test.cpp linux_conio.cpp -o conio.out
./conio.out
```

# Limitations
This is not a full implementation of `conio.h`, it only implements `_getch()` and `_kbhit()`, which are the most important functions from `conio.h`, and also the hardest to implement on Linux.

To achieve this functionality on Linux, the application changes the terminal settings, which has some caveats:
* `enable_conio_mode()` needs to be called before any functionality is used
* `disable_conio_mode()` needs to be called if you want to take normal input with std::cin
* `disable_conio_mode` needs to be called when the program exits, else the console will glitch.
* When a terminating signal which can not be handled (eg. SIGKILL or SIGSTOP) is sent, *conio mode* does not get automatically disabled and will glitch the console. (SIGINT, SIGTERM, SIGQUIT and SIGTSTP is properly handled and cleaned up though)

# Future work
* Implement more functions from `conio.h` (Not very important)