#ifndef WINLIN_H_INCLUDED
#define WINLIN_H_INCLUDED

//Unabhängige Bibliotheken
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

//Windows Bibliotheken
#ifdef __MINGW32__              //Überprüfen ob Windows verwendet wird
    #include <conio.h>
    #include <windows.h>
#endif                          //Ende Windows überprüfung

//Linux Bibliotheken
#ifdef __linux__                //Überprüfen ob Linux verwendet wird
    #include <termios.h>
#endif                          //Ende Linux überprüfung

//Einlesen eines char's ohne Eingabe
int wl_getch(void);
//Löschen des Terminal Fensters
void wl_clear(void);
//Programm wartet in Millisekunden
void wl_sleep(unsigned int uiSleepSeconds);

#endif                          // WINLIN_H_INCLUDED
