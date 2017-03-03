## WinLin

WinLin ist eine C Bibliothek die Windows Befehle in Linux unterstützt.

## Befehle

In der Bibliothek sind folgende Befehle vorhanden:

* getch()
* sleep()
* system("clear")

## Installation

Header- und C-Datei in den Projektordner verschieben und in der main.c die Header-Datei inkludieren.

## Verwendung der Befehle

Jeweils die gewuenschte Funktion aufrufen:

* wl_getch()
* wl_sleep("Zeit in Millisekunden");
* wl_clear();

## bald vorhandene Befehle

* kbhit
* goto(xy)
