#include "linux_conio.h"
#include <thread>

int main() {
    setup_signal_interceptor();
    enable_conio_mode();
    
    printf("Sleeping for 3 seconds\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    printf("Starting...\n");
    if (_kbhit()) {
        printf("Entered while sleeping: %c\n", _getch());
    }
    
    printf("Sleeping for 3 seconds\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Char1: %c | ", _getch());
    printf("Char2: %c\n", _getch());
    
    printf("Sleeping for 5 seconds, queue up characters...\n");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    printf("Queued: ");
    while (_kbhit()) {
        char c = _getch();
        printf("%c", c);
    }
    
    printf("\nTaking input with getch_noblock... Press q to stop\n");
    while (true) {
        char c;
        if ((c = getch_noblock()) != EOF) {
            if (c == 'q') // break on q
                break;
            
            printf("%c", c);
        }
    }
    
    printf("\nTaking input with kbhit + getch... Press q to stop\n");
    while (true) {
        if (_kbhit()) {
            char c = _getch();
            if (c == 'q') // break on q
                break;
            
            printf("%c", c);
        }
    }
    
    disable_conio_mode();
    printf("\nExiting\n");
    return 0;
}