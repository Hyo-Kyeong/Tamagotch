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
	cout << "  �����  ���    �������  ���                    \n";
	cout << "  �����  ���    �������  ���                    \n";
	cout << "  ���      ����  ���    ���  ����                  \n";
	cout << "  ���      ����  ���    ���  ����                  \n";
	cout << "  �����  ���    �������  ���                    \n";
	cout << "  �����  ���    �������  ���                    \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                        �������      ���      ���  \n";
	cout << "                        �������  �������  ���  \n";
	cout << "                                ���  �������  ���  \n";
	cout << "                            ���          ���      ���  \n";
	cout << "                        �������    �����    ���  \n";
	cout << "                        �������  ���    ���  ���  \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";
	cout << "                                                          \n";

	gotoxy(3, 10);
	cout << "����������������������������";
	gotoxy(3, 11);
	cout << "�� 1.���ӽ��� ��";
	gotoxy(3, 12);
	cout << "�� 2.�������� ��";
	gotoxy(3, 13);
	cout << "����������������������������";
	gotoxy(3, 16);
	cout << "                   ";
	gotoxy(3, 16);
	cout << "�� ";

	cin >> key;

	while (1) {
		if (key == "���ӽ���" || key == "1") {
			DamaPlay();
			break;
		}
		else if (key == "��������" || key == "2") {
			GameExit();
		}
		else
		{
			gotoxy(3, 17);
			cout << "                   ";
			gotoxy(3, 17);
			cout << "�� ";
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

		if (dm->level == 0) { // ���� 0 �⺻ ��� 
			cout << " �ش��ϴ� �޴� ��ȣ�� �Է����ּ���!";
			gotoxy(1, 1);
			cout << "����������������\n";
			cout << "��  -=MENU=-  ��\n";
			cout << "��            ��\n";
			cout << "��            ��\n";
			cout << "��            ��\n";
			cout << "��1. �����ֱ� ��\n";
			cout << "��2. ����ֱ� ��\n";
			cout << "��3. �����ϱ� ��\n";
			cout << "��4. ���ڱ�   ��\n";
			cout << "��-. ����  �� ��\n";
			cout << "��   �������� ��\n";
			cout << "��            ��\n";
			cout << "��            ��\n";
			cout << "��            ��\n";
			cout << "����������������\n";
			cout << " �ش��ϴ� �޴� ��ȣ�� �Է����ּ���!";
			gotoxy(1, 1);
		}
		if (kbhit()) { // Ű�� �Է� �޾����� 
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
				cout << "�ٸ���ġ�� ������ �����ϰ� ������ �����մϴ�.\n";
				SaveFile(&dm);
				GameExit();
			}
		}

	}
	void GameManager::GameExit()
	{
		cout << "������ �����մϴ�.";
		exit(0);
	}
	int GameManager::SelectFile()
	{
		string key;
		int file = 1;
		gotoxy(3, 10);
		cout << "������������������������������������";
		gotoxy(3, 11);
		cout << "�� ���̺� ���� 1  ��";
		gotoxy(3, 12);
		cout << " ---------------- ";
		gotoxy(3, 13);
		cout << "�� ���̺� ���� 2  ��";
		gotoxy(3, 14);
		cout << " ---------------- ";
		gotoxy(3, 15);
		cout << "�� ���̺� ���� 3  ��";
		gotoxy(3, 16);
		cout << "������������������������������������";
		gotoxy(3, 18);
		cout << "                   ";
		gotoxy(3, 18);
		cout << "�� ";

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

		//���Ͽ� ����ġ���� ���� 
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
		//�������� �б�
		fscanf(f, "%s %d %d %d %d %d", name, &(dm->fool), &(dm->heart), &(dm->clean), &(dm->tired), &(dm->level));
		dm->name = name;

	}
