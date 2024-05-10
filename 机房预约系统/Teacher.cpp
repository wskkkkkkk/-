#include"Teacher.h"

//教师菜单显示
void Teacher::operMenu() {
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.查看所有预约             |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.审核预约                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.注销登录                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "请输入你的选择：";
}

//无参构造
Teacher::Teacher() {

}

//有参构造
Teacher::Teacher(int empid, string name, string pwd) {
	this->empId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}




//显示所有的预约申请
void Teacher::showAllOrder() {
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
				else {
					cout << "预约日期：" << "周五" << " ";
				}
			}
			else if ((*mit).first == "time") {
				if ((*mit).second == "1") {
					cout << "时段：" << "上午" << " ";
				}
				else {
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

//审核预约
void Teacher::vaildOrder() {
	Order o;
	vector<int>v1;
	int index = 0;
	if (o.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中的记录可以审核，请输入需要审核的记录" << endl;
	for (map<int, map<string, string>>::iterator it = o.m_orderDate.begin(); it != o.m_orderDate.end(); it++) {
				for (map<string, string>::iterator mit1 = (*it).second.begin(); mit1 != (*it).second.end(); mit1++) {
					if ((*mit1).first == "status") {
						if ((*mit1).second == "1" ) {
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
										cout << "状态：审核中" << " ";
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

	cout << "请输入要审核的记录，0代表返回" << endl;
	int select;
	cin >> select;
	bool falg = true;
	for (vector<int>::iterator vit = v1.begin(); vit != v1.end(); vit++) {
		if ((*vit) == select) {
			falg = false;
		}
	}
	if (falg == false) {
		cout << "请输入审核结果" << endl;
		cout << "1、通过" << endl;
		cout << "2、不通过" << endl;
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
								cout << "输入有误，请重新输入：" << endl;
								cin >> passornopass;
							}
						}
						cout << "审核完毕" << endl;
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