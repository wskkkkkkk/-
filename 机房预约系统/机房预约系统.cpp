#include<iostream>
#include"Control.h"
#include"globalFile.h"
#include<fstream>
using namespace std;



int main() {
 	int choice = 0;
	Control c;
	while (true) {
		c.m_Menu();
		cin >> choice;

		switch (choice) {
		case 1:
			c.LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			c.LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			c.LoginIn(ADMINE_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			break;
		}
		system("cls");
	}
	return 0;
}