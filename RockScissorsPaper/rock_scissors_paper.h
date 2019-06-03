#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

void showExit(); 
int main_menu();
void sys(char a);
void play();
void statistics();
void settings();
void ranking();
void threeRound(); // »ï¼¼ÆÇ ÇÔ¼ö 
void showScore(int userScore, int comScore);
void wait(float a);
void gotoxy(int x, int y);
void cursorView(char show);
void winScreen();
void defeatScreen();
