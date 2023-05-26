#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*CONIO.H compatibility on linux*/
#ifdef _WIN32
    #ifdef _WIN64
        // 64-bit Windows
        #include <conio.h>
    #else
        // 32-bit Windows
        #include <conio.h>
    #endif
#else
    // Non-Windows platforms
    #include <curses.h>
#endif

#ifndef FUNCTION_H

/*UTILITY FUNCTION*/
#define clrterm() printf("\e[1;1H\e[2J")
// #define display_line(...) DISPLAY_LINE(__VA_ARGS__,0, 30, 30, true)
// #define DISPLAY_LINE(element, hasTabs,  count, isBreak, ...) display_line(element, hasTabs,  count, isBreak)

/*PROTOTYPES*/
int processing_screen(void);
int aborting_screen(void);
int PINcheck(char PIN[6]);
float deposit(float amnt);
float withdraw(float amnt);
int PINcompare(const char PIN[6], const char PIN2[6]);
int inquiry(void);
void exit_menu(int conf);

#endif