#pragma once
#include"Identity.h"
#include<fstream>
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"
#include"globalFile.h"

class Manager : public Identity {
public:
	Manager();//默认构造

	Manager(string name,string pwd);//有参构造

	virtual void operMenu();//管理员菜单

	void addPerson();//添加账号

	void showPerson();//查看账号

	void showComputer();//查看机房信息

	void cleanFile();//清空预约记录

	void initVector();//初始化容器

	void initComVector();//初始化机房容器

	vector<Student>vStu;//学生容器

	vector<Teacher>vTea;//教师容器

	vector<ComputerRoom>vCom;//机房信息容器
};
