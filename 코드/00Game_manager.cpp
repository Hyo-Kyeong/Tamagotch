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
	cout << "  ﹥﹥﹥﹥  ﹥﹥    ﹥﹥﹥﹥﹥﹥  ﹥﹥                    \n";
	cout << "  ﹥﹥﹥﹥  ﹥﹥    ﹥﹥﹥﹥﹥﹥  ﹥﹥                    \n";
	cout << "  ﹥﹥      ﹥﹥﹥  ﹥﹥    ﹥﹥  ﹥﹥﹥                  \n";
	cout << "  ﹥﹥      ﹥﹥﹥  ﹥﹥    ﹥﹥  ﹥﹥﹥                  \n";
	cout << "  ﹥﹥﹥﹥  ﹥﹥    ﹥﹥﹥﹥﹥﹥  ﹥﹥                    \n";
	cout << "  ﹥﹥﹥﹥  ﹥﹥    ﹥﹥﹥﹥﹥﹥  ﹥﹥                    \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                        ﹥﹥﹥﹥﹥﹥      ﹥﹥      ﹥﹥  \n";
	cout << "                        ﹥﹥﹥﹥﹥﹥  ﹥﹥﹥﹥﹥﹥  ﹥﹥  \n";
	cout << "                                ﹥﹥  ﹥﹥﹥﹥﹥﹥  ﹥﹥  \n";
	cout << "                            ﹥﹥          ﹥﹥      ﹥﹥  \n";
	cout << "                        ﹥﹥﹥﹥﹥﹥    ﹥﹥﹥﹥    ﹥﹥  \n";
	cout << "                        ﹥﹥﹥﹥﹥﹥  ﹥﹥    ﹥﹥  ﹥﹥  \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";

	gotoxy(3, 10);
	cout << "旨收收收收收收收收收收收收旬";
	gotoxy(3, 11);
	cout << "早 1.啪歜衛濛 早";
	gotoxy(3, 12);
	cout << "早 2.啪歜謙猿 早";
	gotoxy(3, 13);
	cout << "曲收收收收收收收收收收收收旭";
	gotoxy(3, 16);
	cout << "                   ";
	gotoxy(3, 16);
	cout << "Ｃ ";

	cin >> key;

	while (1) {
		if (key == "啪歜衛濛" || key == "1") {
			DamaPlay();
			break;
		}
		else if (key == "啪歜謙猿" || key == "2") {
			GameExit();
		}
		else
		{
			gotoxy(3, 17);
			cout << "                   ";
			gotoxy(3, 17);
			cout << "Ｃ ";
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

		if (dm->level == 0) { // 釭檜 0 晦獄 轎溘 
			cout << " п渡ж朝 詭景 廓?ㄧ? 殮溘п輿撮蹂!";
			gotoxy(1, 1);
			cout << "旨收收收收收收旬\n";
			cout << "早  -=MENU=-  早\n";
			cout << "早            早\n";
			cout << "早            早\n";
			cout << "早            早\n";
			cout << "早1. 詳檜輿晦 早\n";
			cout << "早2. 啾嬴輿晦 早\n";
			cout << "早3. 凜錶ж晦 早\n";
			cout << "早4. 濡濠晦   早\n";
			cout << "早-. 盪濰  ?? 早\n";
			cout << "早   啪歜謙猿 早\n";
			cout << "早            早\n";
			cout << "早            早\n";
			cout << "早            早\n";
			cout << "曲收收收收收收旭\n";
			cout << " п渡ж朝 詭景 廓?ㄧ? 殮溘п輿撮蹂!";
			gotoxy(1, 1);
		}
		if (kbhit()) { // 酈蒂 殮溘 嫡懊擊陽 
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
				cout << "棻葆堅纂曖 薑爾蒂 盪濰ж堅 啪歜擊 謙猿м棲棻.\n";
				SaveFile(&dm);
				GameExit();
			}
		}

	}
	void GameManager::GameExit()
	{
		cout << "啪歜擊 謙猿м棲棻.";
		exit(0);
	}
	int GameManager::SelectFile()
	{
		string key;
		int file = 1;
		gotoxy(3, 10);
		cout << "旨收收收收收收收收收收收收收收收收旬";
		gotoxy(3, 11);
		cout << "早 撮檜粽 だ橾 1  早";
		gotoxy(3, 12);
		cout << " ---------------- ";
		gotoxy(3, 13);
		cout << "早 撮檜粽 だ橾 2  早";
		gotoxy(3, 14);
		cout << " ---------------- ";
		gotoxy(3, 15);
		cout << "早 撮檜粽 だ橾 3  早";
		gotoxy(3, 16);
		cout << "曲收收收收收收收收收收收收收收收收旭";
		gotoxy(3, 18);
		cout << "                   ";
		gotoxy(3, 18);
		cout << "Ｃ ";

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

		//だ橾縑 鼻鷓纂菟擊 爾婦 
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
		//鼻鷓だ橾 檗晦
		fscanf(f, "%s %d %d %d %d %d", name, &(dm->fool), &(dm->heart), &(dm->clean), &(dm->tired), &(dm->level));
		dm->name = name;

	}
