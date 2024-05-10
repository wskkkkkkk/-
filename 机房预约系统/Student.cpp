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
	cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.申请预约                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.查看我的预约             |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               3.查看所有人预约           |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               4.取消预约                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.注销登录                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "请输入你的选择：";
}

//初始化机房容器
void Student::InitComputerRoomVector() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
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
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int data;
	cin >> data;
	if (data > 5 || data < 1) {
		cout << "输入有误！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	int time;
	cin >> time;
	if (time > 2 || time < 1) {
		cout << "输入有误！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请选择机房：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << (*it).m_id << "号机房容量： " << (*it).m_MaxNum << endl;
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
		cout << "输入有误！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "预约成功！" << endl;
	
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
				cout << num << "、";
				for (map<string, string>::iterator mit1 = (*it).second.begin(); mit1 != (*it).second.end(); mit1++) {
					if ((*mit1).first == "data") {
						if ((*mit1).second == "1") {
							cout << "预约日期：" << "周一" << " ";
						}
						else if ((*mit1).second == "2") {
							cout << "预约日期：" << "周二" << " ";
						}
						else if ((*mit1).second == "3") {
							cout << "预约日期：" << "周三" << " ";
						}
						else if ((*mit1).second == "4") {
							cout << "预约日期：" << "周四" << " ";
						}
						else {
							cout << "预约日期：" << "周五" << " ";
						}
					}
					else if ((*mit1).first == "time") {
						if ((*mit1).second == "1") {
							cout << "时段：" << "上午" << " ";
						}
						else {
							cout << "时段：" << "下午" << " ";
						}
					}
					else if ((*mit1).first == "roomId") {
						cout << "机房：" << (*mit1).second << " ";
					}
					else if ((*mit1).first == "stuId") {
						cout << "学号：" << (*mit1).second << " ";
					}
					else if ((*mit1).first == "stuName") {
						cout << "姓名：" << (*mit1).second << " ";
					}
					else {
						if ((*mit).second == "1") {
							cout << "状态：审核中";
						}
						else if ((*mit).second == "2") {
							cout << "状态：预约已取消";
						}
						else if ((*mit).second == "3") {
							cout << "状态：预约成功";
						}
						else {
							cout << "状态：预约失败";
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
		cout << (*it).first << "、";
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
			if ((*mit).first == "data") {
				if ((*mit).second == "1") {
					cout << "预约日期：" << "周一" << " ";
				}
				else if ((*mit).second == "2") {
					cout << "预约日期：" << "周二" << " ";
				}
				else if ((*mit).second == "3") {
					cout << "预约日期：" << "周三" << " ";
				}
				else if ((*mit).second == "4") {
					cout << "预约日期：" << "周四" << " ";
				}
				else{
					cout << "预约日期：" << "周五" << " ";
				}
			}
			else if ((*mit).first == "time") {
				if ((*mit).second == "1") {
					cout << "时段：" << "上午" << " ";
				}
				else{
					cout << "时段：" << "下午" << " ";
				}
			}
			else if ((*mit).first == "roomId") {
					cout << "机房：" << (*mit).second << " ";
			}
			else if ((*mit).first == "stuId") {
				cout << "学号：" << (*mit).second << " ";
			}
			else if ((*mit).first == "stuName") {
				cout << "姓名：" << (*mit).second << " ";
			}
			else {
				if ((*mit).second == "1") {
					cout << "状态：审核中";
				}
				else if ((*mit).second == "2") {
					cout << "状态：预约已取消";
				}
				else if ((*mit).second == "3") {
					cout << "状态：预约成功";
				}
				else {
					cout << "状态：预约失败";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
			if ((*mit).second == this->m_Name) {
				for (map<string, string>::iterator mit1 = (*it).second.begin(); mit1 != (*it).second.end(); mit1++) {
					if ((*mit1).first == "status") {
						if ((*mit1).second == "1"|| (*mit1).second == "3") {
							v1.push_back((*it).first);
							cout << (*it).first << "、";
							for (map<string, string>::iterator mit2 = (*it).second.begin(); mit2 != (*it).second.end(); mit2++) {
								if ((*mit2).first == "data") {
									if ((*mit2).second == "1") {
										cout << "预约日期：" << "周一" << " ";
									}
									else if ((*mit2).second == "2") {
										cout << "预约日期：" << "周二" << " ";
									}
									else if ((*mit2).second == "3") {
										cout << "预约日期：" << "周三" << " ";
									}
									else if ((*mit2).second == "4") {
										cout << "预约日期：" << "周四" << " ";
									}
									else {
										cout << "预约日期：" << "周五" << " ";
									}
								}
								else if ((*mit2).first == "time") {
									if ((*mit2).second == "1") {
										cout << "时段：" << "上午" << " ";
									}
									else {
										cout << "时段：" << "下午" << " ";
									}
								}
								else if ((*mit2).first == "roomId") {
									cout << "机房：" << (*mit2).second << " ";
								}
								else if ((*mit2).first == "stuId") {
									cout << "学号：" << (*mit2).second << " ";
								}
								else if ((*mit2).first == "stuName") {
									cout << "姓名：" << (*mit2).second << " ";
								}
								else {
									if ((*mit2).second == "1") {
										cout << "状态：审核中"<<" ";
									}
									else if ((*mit2).second == "2") {
										cout << "状态：预约已取消" << " ";
									}
									else if ((*mit2).second == "3") {
										cout << "状态：预约成功" << " ";
									}
									else {
										cout << "状态：预约失败" << " ";
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
	
	cout << "请输入要取消的记录，0代表返回" << endl;
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
						cout << "预约成功" << endl;
						o.updateOder();
					}
				}
			}
		}
	}
	else {
		cout << "输入错误！" << endl;
	}
	system("pause");
	system("cls");
}


