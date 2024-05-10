#include"Student.h"

Student::Student() {

}
Student::Student(int id, string name, string pwd) {
	this->InitComputerRoomVector();
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Student::operMenu() {
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.����ԤԼ                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.�鿴�ҵ�ԤԼ             |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               3.�鿴������ԤԼ           |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               4.ȡ��ԤԼ                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.ע����¼                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "���������ѡ��";
}

//��ʼ����������
void Student::InitComputerRoomVector() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	int id;
	int maxnum;
	vCom.clear();
	while (ifs>>id&&ifs>>maxnum)
	{
		ComputerRoom c1;
		c1.m_id = id;
		c1.m_MaxNum = maxnum;
		this->vCom.push_back(c1);
	}
	
	ifs.close();
}

void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int data;
	cin >> data;
	if (data > 5 || data < 1) {
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	int time;
	cin >> time;
	if (time > 2 || time < 1) {
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ѡ�������" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << (*it).m_id << "�Ż��������� " << (*it).m_MaxNum << endl;
	}
	
	int ComId;
	cin >> ComId;
	bool flag = true;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		if (ComId == (*it).m_id ) {
			flag = false;
			
		}
	}
	if (flag == true) {
		cout << "��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "ԤԼ�ɹ���" << endl;
	
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	//ifstream ifs;
	//string fData;
	//string fTime;
	//string fComId;
	//ifs.close();
	ofs << "data:" << data << " " << "time:" << time << " " << "roomId:" << ComId << " " << "stuId:" << this->m_Id << " " << "stuName:" << this->m_Name << " " << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}


void Student::showMyOrder() {
	int num = 1;
	Order o;
	for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
			if ((*mit).second == this->m_Name) {
				cout << num << "��";
				for (map<string, string>::iterator mit1 = (*it).second.begin(); mit1 != (*it).second.end(); mit1++) {
					if ((*mit1).first == "data") {
						if ((*mit1).second == "1") {
							cout << "ԤԼ���ڣ�" << "��һ" << " ";
						}
						else if ((*mit1).second == "2") {
							cout << "ԤԼ���ڣ�" << "�ܶ�" << " ";
						}
						else if ((*mit1).second == "3") {
							cout << "ԤԼ���ڣ�" << "����" << " ";
						}
						else if ((*mit1).second == "4") {
							cout << "ԤԼ���ڣ�" << "����" << " ";
						}
						else {
							cout << "ԤԼ���ڣ�" << "����" << " ";
						}
					}
					else if ((*mit1).first == "time") {
						if ((*mit1).second == "1") {
							cout << "ʱ�Σ�" << "����" << " ";
						}
						else {
							cout << "ʱ�Σ�" << "����" << " ";
						}
					}
					else if ((*mit1).first == "roomId") {
						cout << "������" << (*mit1).second << " ";
					}
					else if ((*mit1).first == "stuId") {
						cout << "ѧ�ţ�" << (*mit1).second << " ";
					}
					else if ((*mit1).first == "stuName") {
						cout << "������" << (*mit1).second << " ";
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
				num++;
				cout << endl;
			}

		}
		
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder() {
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
				else{
					cout << "ԤԼ���ڣ�" << "����" << " ";
				}
			}
			else if ((*mit).first == "time") {
				if ((*mit).second == "1") {
					cout << "ʱ�Σ�" << "����" << " ";
				}
				else{
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


void Student::cancelOrder() {
	Order o;
	vector<int>v1;
	int index = 0;
	if (o.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
			if ((*mit).second == this->m_Name) {
				for (map<string, string>::iterator mit1 = (*it).second.begin(); mit1 != (*it).second.end(); mit1++) {
					if ((*mit1).first == "status") {
						if ((*mit1).second == "1"|| (*mit1).second == "3") {
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
										cout << "״̬�������"<<" ";
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
			
		
		}
	}
	
	cout << "������Ҫȡ���ļ�¼��0������" << endl;
	int select;
	cin >> select;
	bool falg = true;
	for (vector<int>::iterator vit = v1.begin(); vit != v1.end(); vit++) {
		if ((*vit) == select) {
			falg = false;
		}
	}
	if (falg == false) {

		for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
			if ((*it).first == select) {

				for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
					if ((*mit).first == "status") {
						(*mit).second = "2";
						cout << "ԤԼ�ɹ�" << endl;
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


