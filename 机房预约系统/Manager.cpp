#include"Manager.h"



void Manager :: operMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.����˺�                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.�鿴�˺�                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               3.�鿴����                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               4.���ԤԼ                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.ע����¼                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "���������ѡ��";
}

//Ĭ�Ϲ���
Manager::Manager() {
	
}

//�вι���
Manager::Manager(string name, string pwd) {
	this->initComVector();
	this->initVector();
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Manager::initComVector() {
	int ComId;
	int ComMaxNum;
	ifstream ifs2;
	ifs2.open(COMPUTER_FILE, ios::in);
	if (!ifs2.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	vCom.clear();

	while (ifs2 >> ComId && ifs2 >> ComMaxNum) {
		ComputerRoom c1;
		c1.m_id = ComId;
		c1.m_MaxNum = ComMaxNum;
		vCom.push_back(c1);
	}
	ifs2.close();

}

//��ʼ������
void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	vStu.clear();

	int fId;
	string fName;
	string fPwd;
	while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		Student s1;
		s1.m_Id = fId;
		s1.m_Name = fName;
		s1.m_Pwd = fPwd;
		vStu.push_back(s1);
	}
	
	ifs.close();
	ifstream ifs1;
	ifs1.open(TEACHER_FILE, ios::in);
	if (!ifs1.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	vTea.clear();
	
	while (ifs1 >> fId && ifs1 >> fName && ifs1 >> fPwd) {
		Teacher t1;
		t1.empId = fId;
		t1.m_Name = fName;
		t1.m_Pwd = fPwd;
		vTea.push_back(t1);
	}
	ifs1.close();


}

//����˺�
void Manager::addPerson() {
	int addType;
	int id;
	string name;
	string pwd;
	cout << "����������˺����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	cin >> addType;
	if (addType == 1) {
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (addType == 2) {
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	else {
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << endl;
	cout << "�������û�����";
	cin >> name;

	cout << endl;
	cout << "���������룺";
	cin >> pwd;


	if (addType == 1) {
		int fId;
		string fName;
		string fPwd; 
		ifstream ifs;
		ofstream ofs;
		ofs.open(STUDENT_FILE, ios::out|ios::app);
		ifs.open(STUDENT_FILE, ios::in);
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id) {
				cout << "��ѧ��������ѧ��ѧ���ظ���" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		ofs << id << " " << name << " " << pwd << endl;
		cout << "��ӳɹ���" << endl;
		initVector();
		system("pause");
		system("cls");
		ofs.close();	
	}
	else if (addType == 2) {
		int fId;
		string fName;
		string fPwd;
		ifstream ifs;
		ofstream ofs;
		ofs.open(TEACHER_FILE, ios::out | ios::app);
		ifs.open(TEACHER_FILE, ios::in);
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id) {
				cout << "�ý�ʦ��������ʦְ�����ظ���" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		ofs << id << " " << name << " " << pwd << endl;
		cout << "��ӳɹ���" << endl;
		initVector();
		system("pause");
		system("cls");
		ofs.close();
	}
	
}

//�鿴�˺�
void Manager::showPerson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int addType = 0;
	cin >> addType;
	if (addType == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			cout << "ѧ�ţ�" << (*it).m_Id << "  ������" << (*it).m_Name << "  ���룺" << (*it).m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else if (addType == 2) {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			cout << "ְ���ţ�" << (*it).empId << "  ������" << (*it).m_Name << "  ���룺" << (*it).m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else {
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}

}

//�鿴������Ϣ
void Manager::showComputer() {
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "�����ţ�" << (*it).m_id << "  �������������" << (*it).m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}