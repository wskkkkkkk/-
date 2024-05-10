#include"Control.h"
#include"globalFile.h"
#include<string>
void Control::m_Menu() {
	cout << "=============================欢迎来到机房预约系统=============================" << endl;
	cout << endl << "请输入您的身份：" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.学生代表                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.老    师                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               3.管 理 员                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.退    出                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "请输入您的选择：";
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
			cout << "添加账号" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "查看账号" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "查看机房" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "清空预约" << endl;
			man->cleanFile();
			break;
		case 0:
			delete manager;
			cout << "欢迎下次使用！" << endl;
			system("pause");
			exit(0);
			break;
		default:
			break;
		}
		system("cls");
	}
	
}

//学生菜单
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
			stu->applyOrder();//申请预约
			break;
		case 2:
			stu->showMyOrder();//查看我的预约
			break;
		case 3:
			stu->showAllOrder();//查看所有预约
			break;
		case 4:
			stu->cancelOrder();//取消预约
			break;
		case 0:
			delete student;
			cout << "欢迎下次使用！" << endl;
			system("pause");
			exit(0);
			break;
		default:
			break;
		}
		system("cls");
	}

}

//教师菜单
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
			tea->showAllOrder();//显示所有的预约申请
			break;
		case 2:
			tea->vaildOrder();//审核预约
			break;
		case 0:
			delete teacher;
			cout << "欢迎下次使用！" << endl;
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
		cout << "文件不存在" << endl;
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
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：";
		cin >> id;
	}
	cout << endl;
	cout << "请输入用户名：";
	cin >> name;

	cout << endl;
	cout << "请输入密码：";
	cin >> pwd;

	if (type == 1) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);	
				return;
			}
		}
		cout << "登陆失败！" << endl;
		system("pause");
		return;	
	}
	else if (type == 2) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
		cout << "登陆失败！" << endl;
		system("pause");
		return;
	}
	else if (type == 3) {
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);

				return;
			}
		}
		cout << "登陆失败！" << endl;
		system("pause");
		return;
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
	ifs.close();
}


