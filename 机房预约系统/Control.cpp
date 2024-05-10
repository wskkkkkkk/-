#include"Control.h"
#include"globalFile.h"
#include<string>
void Control::m_Menu() {
	cout << "=============================��ӭ��������ԤԼϵͳ=============================" << endl;
	cout << endl << "������������ݣ�" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.ѧ������                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.��    ʦ                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               3.�� �� Ա                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.��    ��                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "����������ѡ��";
}

void Control::managerMenu(Identity*& manager) {
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����˺�" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "�鿴����" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			man->cleanFile();
			break;
		case 0:
			delete manager;
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
			break;
		default:
			break;
		}
		system("cls");
	}
	
}

//ѧ���˵�
void Control::studentMenu(Identity*& student) {
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			stu->applyOrder();//����ԤԼ
			break;
		case 2:
			stu->showMyOrder();//�鿴�ҵ�ԤԼ
			break;
		case 3:
			stu->showAllOrder();//�鿴����ԤԼ
			break;
		case 4:
			stu->cancelOrder();//ȡ��ԤԼ
			break;
		case 0:
			delete student;
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
			break;
		default:
			break;
		}
		system("cls");
	}

}

//��ʦ�˵�
void Control::teacherMenu(Identity*& teacher) {
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			tea->showAllOrder();//��ʾ���е�ԤԼ����
			break;
		case 2:
			tea->vaildOrder();//���ԤԼ
			break;
		case 0:
			delete teacher;
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
			break;
		default:
			break;
		}
		system("cls");
	}


}
void Control::LoginIn(string filename, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		system("pause");
		ifs.close();
		return;
	}
	
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf))) {
		cout << buf << endl;
	}*/
	int id = 0;
	string name;
	string pwd;
	if (type == 1) {
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	cout << endl;
	cout << "�������û�����";
	cin >> name;

	cout << endl;
	cout << "���������룺";
	cin >> pwd;

	if (type == 1) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);	
				return;
			}
		}
		cout << "��½ʧ�ܣ�" << endl;
		system("pause");
		return;	
	}
	else if (type == 2) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
		cout << "��½ʧ�ܣ�" << endl;
		system("pause");
		return;
	}
	else if (type == 3) {
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);

				return;
			}
		}
		cout << "��½ʧ�ܣ�" << endl;
		system("pause");
		return;
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
	ifs.close();
}


