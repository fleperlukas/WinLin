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

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesarcode(char *szWort,int iV){
    int iX;

    for(iX = 0; iX < sizeof(szWort); iX++){
        if(szWort[iX] +iV == 'Z'){
            szWort[iX] = szWort[iX] + iV;
        }else{
            szWort[iX] = szWort[iX] + iV - 26;
        }
    }
}

int main(){
    int iZ, iV;
    char *szWort;

    printf("Wie lang soll das Wort sein: ");
    scanf("%d", &iZ);       fflush(stdin);

    if((szWort = (char *) malloc((iZ + 1) * sizeof(char))) == NULL){
        printf("Zu wenig Speicher vorhanden!\n");
        return EXIT_FAILURE;
    }

    scanf("%s", szWort);

    printf("Um wie viele stellen soll das Wort verschoben werden? \n");
    scanf("%d", &iV);       fflush(stdin);

    caesarcode(szWort, iV);

    printf("Verschluesselt: %s", szWort);

    return 0;
}

*/
