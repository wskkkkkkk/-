#include"Teacher.h"

//��ʦ�˵���ʾ
void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.�鿴����ԤԼ             |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.���ԤԼ                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.ע����¼                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "���������ѡ��";
}

//�޲ι���
Teacher::Teacher() {

}

//�вι���
Teacher::Teacher(int empid, string name, string pwd) {
	this->empId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}




//��ʾ���е�ԤԼ����
void Teacher::showAllOrder() {
	Order o;
	for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
		cout << (*it).first << "��";
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
			if ((*mit).first == "data") {
				if ((*mit).second == "1") {
					cout << "ԤԼ���ڣ�" << "��һ" << " ";
				}
				else if ((*mit).second == "2") {
					cout << "ԤԼ���ڣ�" << "�ܶ�" << " ";
				}
				else if ((*mit).second == "3") {
					cout << "ԤԼ���ڣ�" << "����" << " ";
				}
				else if ((*mit).second == "4") {
					cout << "ԤԼ���ڣ�" << "����" << " ";
				}
				else {
					cout << "ԤԼ���ڣ�" << "����" << " ";
				}
			}
			else if ((*mit).first == "time") {
				if ((*mit).second == "1") {
					cout << "ʱ�Σ�" << "����" << " ";
				}
				else {
					cout << "ʱ�Σ�" << "����" << " ";
				}
			}
			else if ((*mit).first == "roomId") {
				cout << "������" << (*mit).second << " ";
			}
			else if ((*mit).first == "stuId") {
				cout << "ѧ�ţ�" << (*mit).second << " ";
			}
			else if ((*mit).first == "stuName") {
				cout << "������" << (*mit).second << " ";
			}
			else {
				if ((*mit).second == "1") {
					cout << "״̬�������";
				}
				else if ((*mit).second == "2") {
					cout << "״̬��ԤԼ��ȡ��";
				}
				else if ((*mit).second == "3") {
					cout << "״̬��ԤԼ�ɹ�";
				}
				else {
					cout << "״̬��ԤԼʧ��";
				}
			}
		}
		cout << endl;
	}
	system("pause");
	system("cls");

}

//���ԤԼ
void Teacher::vaildOrder() {
	Order o;
	vector<int>v1;
	int index = 0;
	if (o.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����еļ�¼������ˣ���������Ҫ��˵ļ�¼" << endl;
	for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
				for (map<string, string>::iterator mit1 = (*it).second.begin(); mit1 != (*it).second.end(); mit1++) {
					if ((*mit1).first == "status") {
						if ((*mit1).second == "1" ) {
							v1.push_back((*it).first);
							cout << (*it).first << "��";
							for (map<string, string>::iterator mit2 = (*it).second.begin(); mit2 != (*it).second.end(); mit2++) {
								if ((*mit2).first == "data") {
									if ((*mit2).second == "1") {
										cout << "ԤԼ���ڣ�" << "��һ" << " ";
									}
									else if ((*mit2).second == "2") {
										cout << "ԤԼ���ڣ�" << "�ܶ�" << " ";
									}
									else if ((*mit2).second == "3") {
										cout << "ԤԼ���ڣ�" << "����" << " ";
									}
									else if ((*mit2).second == "4") {
										cout << "ԤԼ���ڣ�" << "����" << " ";
									}
									else {
										cout << "ԤԼ���ڣ�" << "����" << " ";
									}
								}
								else if ((*mit2).first == "time") {
									if ((*mit2).second == "1") {
										cout << "ʱ�Σ�" << "����" << " ";
									}
									else {
										cout << "ʱ�Σ�" << "����" << " ";
									}
								}
								else if ((*mit2).first == "roomId") {
									cout << "������" << (*mit2).second << " ";
								}
								else if ((*mit2).first == "stuId") {
									cout << "ѧ�ţ�" << (*mit2).second << " ";
								}
								else if ((*mit2).first == "stuName") {
									cout << "������" << (*mit2).second << " ";
								}
								else {
									if ((*mit2).second == "1") {
										cout << "״̬�������" << " ";
									}
									else if ((*mit2).second == "2") {
										cout << "״̬��ԤԼ��ȡ��" << " ";
									}
									else if ((*mit2).second == "3") {
										cout << "״̬��ԤԼ�ɹ�" << " ";
									}
									else {
										cout << "״̬��ԤԼʧ��" << " ";
									}
								}
							}
						}
						cout << endl;
					}

				}	
	}

	cout << "������Ҫ��˵ļ�¼��0������" << endl;
	int select;
	cin >> select;
	bool falg = true;
	for (vector<int>::iterator vit = v1.begin(); vit != v1.end(); vit++) {
		if ((*vit) == select) {
			falg = false;
		}
	}
	if (falg == false) {
		cout << "��������˽��" << endl;
		cout << "1��ͨ��" << endl;
		cout << "2����ͨ��" << endl;
		int passornopass;
		cin >> passornopass;
		for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
			if ((*it).first == select) {

				for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
					if ((*mit).first == "status") {
						while (true)
						{
							if (passornopass == 1) {
								(*mit).second = "3";
								break;
							}
							else if (passornopass == 2) {
								(*mit).second = "4";
								break;
							}
							else
							{
								cout << "�����������������룺" << endl;
								cin >> passornopass;
							}
						}
						cout << "������" << endl;
						o.updateOder();
					}
				}
			}
		}
	}
	else {
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");

}