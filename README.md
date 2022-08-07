# Linux implementation of <conio.h>
This project implements the Windows-specific functions `_getch()` and `_kbhit()` from `conio.h`. These functions are used to read characters from stdin, without the user having to press *enter*, with the option to do it in a non-blocking way, which can be used to detect keypresses without having to "pause" the application.

## Cross platform
Despite being an implementation of a Windows API for Linux, this project also works for Windows. The only function which is implemented for Windows and adds onto the already existing functionality is:
```c++
int getch_noblock(); 
```
which is a non-blocking version of `_getch()`, which returns EOF if no character can be read from stdin.

# Compiling
This project compiles on any modern C++ compiler for either Linux or Windows. In this example I will use `gcc`
To compile the project and run the test cases, run:
```
g++ test.cpp linux_conio.cpp -o conio.out
./conio.out
```

# Limitations
This is not a full implementation of `conio.h`, it only implements `_getch()` and `_kbhit()`, which are the most important functions from `conio.h`, and also the hardest to implement on Linux.

# Future work
* Implement more functions from `conio.h` (Not very important)