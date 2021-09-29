#include "00Game_manager.h"

GameManager::GameManager()
{
	filenumber = 1;
}
void GameManager::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void GameManager::GamePlay()
{
	string key;

	cout << "                                                          \n";
	cout << "  ■■■■  ■■    ■■■■■■  ■■                    \n";
	cout << "  ■■■■  ■■    ■■■■■■  ■■                    \n";
	cout << "  ■■      ■■■  ■■    ■■  ■■■                  \n";
	cout << "  ■■      ■■■  ■■    ■■  ■■■                  \n";
	cout << "  ■■■■  ■■    ■■■■■■  ■■                    \n";
	cout << "  ■■■■  ■■    ■■■■■■  ■■                    \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                        ■■■■■■      ■■      ■■  \n";
	cout << "                        ■■■■■■  ■■■■■■  ■■  \n";
	cout << "                                ■■  ■■■■■■  ■■  \n";
	cout << "                            ■■          ■■      ■■  \n";
	cout << "                        ■■■■■■    ■■■■    ■■  \n";
	cout << "                        ■■■■■■  ■■    ■■  ■■  \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";

	gotoxy(3, 10);
	cout << "┏━━━━━━━━━━━━┓";
	gotoxy(3, 11);
	cout << "┃ 1.게임시작 ┃";
	gotoxy(3, 12);
	cout << "┃ 2.게임종료 ┃";
	gotoxy(3, 13);
	cout << "┗━━━━━━━━━━━━┛";
	gotoxy(3, 16);
	cout << "                   ";
	gotoxy(3, 16);
	cout << "☞ ";

	cin >> key;

	while (1) {
		if (key == "게임시작" || key == "1") {
			DamaPlay();
			break;
		}
		else if (key == "게임종료" || key == "2") {
			GameExit();
		}
		else
		{
			gotoxy(3, 17);
			cout << "                   ";
			gotoxy(3, 17);
			cout << "☞ ";
			cin >> key;

		}
	}
}
void GameManager::DamaPlay()
{
	Dama dm;
	char c;
	filenumber = SelectFile();
	LoadFile(&dm);
	char c;
	system("cls");
	for (;;) {

		if (dm->level == 0) { // 나이 0 기본 출력 
			cout << " 해당하는 메뉴 번호를 입력해주세요!";
			gotoxy(1, 1);
			cout << "┏━━━━━━┓\n";
			cout << "┃  -=MENU=-  ┃\n";
			cout << "┃            ┃\n";
			cout << "┃            ┃\n";
			cout << "┃            ┃\n";
			cout << "┃1. 먹이주기 ┃\n";
			cout << "┃2. 놀아주기 ┃\n";
			cout << "┃3. 샤워하기 ┃\n";
			cout << "┃4. 잠자기   ┃\n";
			cout << "┃-. 저장  후 ┃\n";
			cout << "┃   게임종료 ┃\n";
			cout << "┃            ┃\n";
			cout << "┃            ┃\n";
			cout << "┃            ┃\n";
			cout << "┗━━━━━━┛\n";
			cout << " 해당하는 메뉴 번호를 입력해주세요!";
			gotoxy(1, 1);
		}
		if (kbhit()) { // 키를 입력 받았을때 
			c = getch();
			if (c == '1')
			{
				dm->Feed();
				system("cls");
				continue;
			}
			else if (c == '2')
			{
				dm->Enjoy();
				system("cls");
				continue;
			}
			else if (c == '3')
			{
				dm->Shower();
				system("cls");
				continue;
			}
			else if (c == '4')
			{
				dm->sleep();
				system("cls");
				continue;
			}
			else if (c == '-')
			{
				gotoxy(1, 19);
				cout << "다마고치의 정보를 저장하고 게임을 종료합니다.\n";
				SaveFile(&dm);
				GameExit();
			}
		}

	}
	void GameManager::GameExit()
	{
		cout << "게임을 종료합니다.";
		exit(0);
	}
	int GameManager::SelectFile()
	{
		string key;
		int file = 1;
		gotoxy(3, 10);
		cout << "┏━━━━━━━━━━━━━━━━┓";
		gotoxy(3, 11);
		cout << "┃ 세이브 파일 1  ┃";
		gotoxy(3, 12);
		cout << " ---------------- ";
		gotoxy(3, 13);
		cout << "┃ 세이브 파일 2  ┃";
		gotoxy(3, 14);
		cout << " ---------------- ";
		gotoxy(3, 15);
		cout << "┃ 세이브 파일 3  ┃";
		gotoxy(3, 16);
		cout << "┗━━━━━━━━━━━━━━━━┛";
		gotoxy(3, 18);
		cout << "                   ";
		gotoxy(3, 18);
		cout << "☞ ";

		cin >> key;
		if (key == "1") return 1;
		if (key == "2") return 2;
		if (key == "3") return 3;
	}
	void GameManager::SaveFile(Dama *dm)
	{
		FILE *f;
		char *name = new char[dm->name.size() + 1];
		strcpy(name, dm->name.c_str());

		if (filenumber == 1)
			FILE *f = fopen("data1.txt", "w+t");
		if (filenumber == 2)
			FILE *f = fopen("data2.txt", "w+t");
		if (filenumber == 3)
			FILE *f = fopen("data3.txt", "w+t");

		//파일에 상태치들을 보관 
		fprintf(f, "%s %d %d %d %d %d", name, dm->fool, dm->heart, dm->clean, dm->tired, dm->level);
		fclose(f);
		delete name;
	}
	void GameManager::LoadFile(Dama *dm)
	{
		FILE *f;
		char *name = new char[dm->name.size() + 1];

		if (filenumber == 1)
			FILE *f = fopen("data1.txt", "rt");
		if (filenumber == 2)
			FILE *f = fopen("data2.txt", "rt");
		if (filenumber == 3)
			FILE *f = fopen("data3.txt", "rt");
		if (f == NULL) {
			dm->Init();
			system("cls");
		}
		//상태파일 읽기
		fscanf(f, "%s %d %d %d %d %d", name, &(dm->fool), &(dm->heart), &(dm->clean), &(dm->tired), &(dm->level));
		dm->name = name;

	}
