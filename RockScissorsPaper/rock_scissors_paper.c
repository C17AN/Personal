#include "rock_scissors_paper.h"

void cursorView(char show) // 커서숨기기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void wait(float a) // 1초를 기다리는 함수 
{
	clock_t end;
	end = clock() + CLOCKS_PER_SEC * a;
	while(end > clock()){}
}

void gotoxy(int x, int y) // 커서 좌표 이동용 함수 
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void showExit() // 종료화면 표시용 함수 
{
	int i, moveCnt;
	char key;
	gotoxy(12, 5);
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("┏");
		else if(i < 21) printf("━");
		else printf("┓\n");
	}
	gotoxy(12, 6);
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("┃");
		else if(i < 21) printf(" ");
		else printf("┃\n");
	}
	gotoxy(12, 7);
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("┃");
		else if(i < 21) printf(" ");
		else printf("┃\n");
	}
	gotoxy(12, 8);	
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("┗");
		else if(i < 21) printf("━");
		else printf("┛\n");
	}
	gotoxy(13, 6);
	printf("  게임을 종료할까요?");
	gotoxy(13, 7);
	printf("    Yes   /   No   ");
	sleep(100);
} 

void showScore(int userScore, int comScore)
{
	gotoxy(18, 4);
	printf("%d", userScore);
	gotoxy(22, 4);
	printf(":");
	gotoxy(26, 4);
	printf("%d", comScore);
}

void winScreen(int user_win, int com_win)
{
	gotoxy(0,0);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■           ----- 경기 결과 -----            ■");
	puts("■                                            ■");					
	puts("■      [나]                    [컴퓨터]      ■");
	puts("■                                            ■");		
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■                                            ■");							
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■■■■■■■■■■■■■■■■■■■■■■■■"); 
	showScore(user_win, com_win);
	gotoxy(13, 7); 
	printf("★☆★ 승 리! ★☆★");
	wait(2);
} 

void defeatScreen(int user_win, int com_win)
{
	gotoxy(0,0);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■           ----- 경기 결과 -----            ■");
	puts("■                                            ■");					
	puts("■      [나]                    [컴퓨터]      ■");
	puts("■                                            ■");		
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■                                            ■");							
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■■■■■■■■■■■■■■■■■■■■■■■■"); 
	showScore(user_win, com_win);
	gotoxy(20, 7); 
	printf("패 배!");
	wait(2);
}

void sys(char select) // 메인메뉴 백엔드 함수 
{	
	switch(select)
	{
		case '1':
			play();
			break;
		case '2':
			statistics();
			break;
		case '3':
			settings();
			break;
		case '4':
			ranking();
			break;
		case '5':
			showExit();
			break;
		default:
			main_menu();
	}
}

int main_menu() // 메인메뉴 출력 함수 
{
	char select;
	//  가로 28칸 , 세로 13칸 
	gotoxy(0,0);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");  
	puts("■□■□■                            ■□■□■");	
	puts("■■□■■ 가위 바위 보 게임 v.1.0.0  ■■□■■");
	puts("■□■□■                            ■□■□■");	
	puts("■■□■■         [ 메  뉴 ]         ■■□■■");
	puts("■□■□■                            ■□■□■");
	puts("■■□■■ 1. 플레이                  ■■□■■");
	puts("■□■□■ 2. 통 계                   ■□■□■");
	puts("■■□■■ 3. 설 정                   ■■□■■");
	puts("■□■□■ 4. 랭 킹                   ■□■□■");	
	puts("■■□■■ 5. 게임 종료               ■■□■■");	
	puts("■□■□■                            ■□■□■");		
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	cursorView(0);	
	select = getch(); // 입력받아 메뉴 선택  
	return select;
}

void play() // 1번 플레이 메뉴 
{	
	int i;
	char computer, user;
	char select;
	system("cls"); // 화면 초기화용 함수 
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■      --------    모드 선택   --------      ■");		
	puts("■                                            ■");	
	puts("■ 1. 정통 가위바위보 한판! - 삼세판 모드     ■");
	puts("■                                            ■");
	puts("■ 2. 컴퓨터와의 끝없는  승부! - 무한 모드    ■");
	puts("■                                            ■");
	puts("■ 3. 진정한 실력대결! - 하나 빼기 일 모드    ■");					
	puts("■                                            ■");							
	puts("■ 4. 뒤로 가기                               ■");	
	puts("■                                            ■");			
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	cursorView(0);	
	select = getch();
	system("cls");
	switch(select)
	{
		case '1':	
			threeRound();
			break;
		case '2':
			printf("무한");
			break;
		case '3':
			printf("하나빼기일");
			break;
		default:
			main_menu();
			break;
	}
}

void statistics()
{
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■                                            ■");	
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");					
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■                                            ■");			
	puts("■                                            ■");			
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	sleep(100);	
}

void settings()
{
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■                                            ■");	
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");					
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■                                            ■");			
	puts("■                                            ■");			
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	sleep(100);	
}

void ranking()
{
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■                                            ■");	
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");					
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■                                            ■");			
	puts("■                                            ■");			
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	sleep(100);	
}

void threeRound()
{	
	int userHand = 0, computerHand = 0; // 컴퓨터와 플레이어의 손 모양
	// 플레이어는 1, 0, -1 중 하나의 값을 가지며, 각각 가위 / 바위 / 보를 의미함. 
	// 컴퓨터는 0, 1, 2 중 하나의  값을 가지며, 각각 가위 / 바위 / 보를 의미함. 
	int x = 15, y = 8;
	int input = 0;
	int com_win = 0, user_win = 0;
	int i = 0;
	
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■      --------   규칙 설명   --------       ■");
	puts("■                                            ■");					
	puts("■   삼세판 모드는 가장 기본적인 모드입니다.  ■");
	puts("■                                            ■");		
	puts("■ 한 플레이어가 세 판을 이길 시, 승리합니다! ■");
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■                                            ■");							
	puts("■                                            ■");	
	puts("■                                            ■");			
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	cursorView(0);		
	for(i = 3; i >= 1; --i)
	{
		gotoxy(10, 10);
		printf("%d 초 후 경기가 시작됩니다.", i);
		cursorView(0);			
		wait(1);
	}
	system("cls");
	puts("■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                            ■");
	puts("■                                            ■");
	puts("■                                            ■");					
	puts("■                                            ■");
	puts("■                                            ■");		
	puts("■                 경기 시작 !                ■");
	puts("■                                            ■");
	puts("■                                            ■");				
	puts("■                                            ■");							
	puts("■                                            ■");	
	puts("■                                            ■");			
	puts("■■■■■■■■■■■■■■■■■■■■■■■■"); 
	wait(1);
	
	while(com_win < 3 && user_win < 3) 
	{
		i++;	// 라운드 표시용  
		srand(time(NULL));
		computerHand = rand() % 3; // 컴퓨터의 손모양 설정 (0, 1, 2 -> 가위, 바위, 보) 
		
		while(input != 13)
		{	
		
			input = getch();
			switch(input)
			{
				case UP:
					if(userHand == 1) continue;
					userHand++;
					gotoxy(0,0);
					puts("■■■■■■■■■■■■■■■■■■■■■■■■");
					puts("■                                            ■");
					puts("■           -----  Round    -----            ■");
					puts("■                                            ■");					
					puts("■      [나]                    [컴퓨터]      ■");
					puts("■                                            ■");		
					puts("■      가위                                  ■");
					puts("■                                            ■");
					puts("■      바위                      ???         ■");				
					puts("■                                            ■");							
					puts("■       보                                   ■");	
					puts("■                                            ■");				
					puts("■■■■■■■■■■■■■■■■■■■■■■■■");
					gotoxy(27, 2);
					printf("%d", i);											
					gotoxy(x, y);
					printf("  ");
					gotoxy(x, y-2);
					y -= 2;
					printf("◀");
					break;
				case DOWN:
					if(userHand == -1) continue;
					userHand--;
					gotoxy(0,0);
					puts("■■■■■■■■■■■■■■■■■■■■■■■■");
					puts("■                                            ■");
					puts("■           -----  Round    -----            ■");
					puts("■                                            ■");					
					puts("■      [나]                    [컴퓨터]      ■");
					puts("■                                            ■");		
					puts("■      가위                                  ■");
					puts("■                                            ■");
					puts("■      바위                      ???         ■");				
					puts("■                                            ■");							
					puts("■       보                                   ■");	// 17, 25, 4
					puts("■                                            ■");				
					puts("■■■■■■■■■■■■■■■■■■■■■■■■");
					gotoxy(27, 2);
					printf("%d", i);											
					gotoxy(x, y);
					printf("  ");
					gotoxy(x, y+2);
					y += 2;
					printf("◀");
					break;
			} 	
		}
		switch(userHand)
		{
			case 1: // 유저 : 가위 
				switch(computerHand)
				{
					case 0: // 컴퓨터 : 가위  
					gotoxy(33, 8);
					printf(" 가위!");
					cursorView(0);
					showScore(user_win, com_win);					
					wait(1);
					
					break;
					
					case 1: // 컴퓨터 : 바위 
					gotoxy(33, 8);
					printf(" 바위!");
					cursorView(0);
					com_win++;
					showScore(user_win, com_win);						
					wait(1);
					break;
					
					case 2: // 컴퓨터 : 보 
					gotoxy(33, 8);
					printf(" 보!");
					cursorView(0);
					user_win++;
					showScore(user_win, com_win);						
					wait(1);
				}
			break;
			
			case 0: // 유저 : 바위 
				switch(computerHand)
				{
					case 0: // 컴퓨터 : 가위  
					gotoxy(33, 8);
					printf(" 가위!");
					cursorView(0);
					user_win++; 
					showScore(user_win, com_win);					
					wait(1);
					break;
					
					case 1: // 컴퓨터 : 바위 
					gotoxy(33, 8);
					printf(" 바위!");
					cursorView(0);
					showScore(user_win, com_win);					
					wait(1);
					break;
					
					case 2: // 컴퓨터 : 보 
					gotoxy(33, 8);
					printf(" 보!");
					cursorView(0);
					com_win++;
					showScore(user_win, com_win);					
					wait(1);
				}
			break;
			
			case -1: // 유저 : 보 
				switch(computerHand)
				{
					case 0: // 컴퓨터 : 가위  
					gotoxy(33, 8);
					printf(" 가위!");
					cursorView(0);
					com_win++;
					showScore(user_win, com_win);					 	
					wait(1);
					break;
					
					case 1: // 컴퓨터 : 바위 
					gotoxy(33, 8);
					printf(" 바위!");
					cursorView(0);
					user_win++;
					showScore(user_win, com_win);					
					wait(1);
					break;
					
					case 2: // 컴퓨터 : 보 
					gotoxy(33, 8);
					printf(" 보!");
					cursorView(0);
					showScore(user_win, com_win);					
					wait(1);
				}
			break;					
		}
		
		if(user_win >= 3) winScreen(user_win, com_win);
		else if (com_win >= 3)defeatScreen(user_win, com_win);		
		
		input = 0;
		x = 15;
		y = 8;
		userHand = 0;
		computerHand = 0;
	}
	user_win = 0, com_win = 0;
}
