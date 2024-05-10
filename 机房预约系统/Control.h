#pragma once
#include<iostream>
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include<fstream>
#include"globalFile.h"
using namespace std;


class Control {
public:
	void m_Menu();

	void LoginIn(string filename, int type);//登录函数

	void managerMenu(Identity*& manager);//管理员菜单

	void studentMenu(Identity*& student);//学生菜单

	void teacherMenu(Identity*& teacher);//老师菜单

};
