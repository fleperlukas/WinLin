//winlin.h inkludieren
#include "winlin.h"

//Einlesen eines char's ohne Eingabe
int wl_getch(void);
//Löschen des Terminal Fensters
void wl_clear(void);
//Programm wartet in Millisekunden
void wl_sleep(unsigned int uiSleepSeconds);

//Überprüfen ob Windows verwedet wird
#ifdef __MINGW32__
    int wl_getch()
    {
        int i = getch();
        return i;
    }

    void wl_clear(void)
    {
        system("cls");
    }

    void wl_sleep(unsigned int uiSleepSeconds)
    {
        Sleep(uiSleepSeconds*1000);                 //in Millisekunden
    }
#endif // __MINGW32__

//Überprüfen ob Linux verwendet wird
#ifdef __linux__
    int wl_getch(void)
    {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    }

    void wl_clear(void)
    {
        system("clear");
    }

    void wl_sleep(unsigned int uiSleepSeconds)
    {
        sleep(uiSleepSeconds);
    }
#endif // __linux__
