#include <stdio.h>
#include <stdlib.h>
#include "rock_scissors_paper.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int highScore; // 무한모드용 하이스코어 
int winWithR, winWithS, winWithP; // 가위 / 바위 / 보 로 이긴 횟수들 

int main(int argc, char *argv[]) {
	system("mode con: cols=50 lines=14"); // 창 크기조절 
	while(1)
	{
		sys(main_menu());
	}
}
