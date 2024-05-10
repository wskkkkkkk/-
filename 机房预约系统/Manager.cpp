#include"Manager.h"



void Manager :: operMenu() {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               1.添加账号                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               2.查看账号                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               3.查看机房                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               4.清空预约                 |\n";
	cout << "\t\t|                                          |\n";
	cout << "\t\t|               0.注销登录                 |\n";
	cout << "\t\t-------------------------------------------\n";
	cout << "请输入你的选择：";
}

//默认构造
Manager::Manager() {
	
}

//有参构造
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
		cout << "文件打开失败" << endl;
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

//初始化容器
void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
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
		cout << "文件打开失败" << endl;
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

//添加账号
void Manager::addPerson() {
	int addType;
	int id;
	string name;
	string pwd;
	cout << "请输入添加账号类型：" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	cin >> addType;
	if (addType == 1) {
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (addType == 2) {
		cout << "请输入你的职工号：";
		cin >> id;
	}
	else {
		cout << "输入有误！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << endl;
	cout << "请输入用户名：";
	cin >> name;

	cout << endl;
	cout << "请输入密码：";
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
				cout << "该学号与其他学生学号重复！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		ofs << id << " " << name << " " << pwd << endl;
		cout << "添加成功！" << endl;
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
				cout << "该教师与其他教师职工号重复！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		ofs << id << " " << name << " " << pwd << endl;
		cout << "添加成功！" << endl;
		initVector();
		system("pause");
		system("cls");
		ofs.close();
	}
	
}

//查看账号
void Manager::showPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int addType = 0;
	cin >> addType;
	if (addType == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			cout << "学号：" << (*it).m_Id << "  姓名：" << (*it).m_Name << "  密码：" << (*it).m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else if (addType == 2) {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			cout << "职工号：" << (*it).empId << "  姓名：" << (*it).m_Name << "  密码：" << (*it).m_Pwd << endl;
		}
		system("pause");
		system("cls");
	}
	else {
		cout << "输入有误！" << endl;
		system("pause");
		system("cls");
		return;
	}

}

//查看机房信息
void Manager::showComputer() {
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "机房号：" << (*it).m_id << "  机房最大容量：" << (*it).m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}