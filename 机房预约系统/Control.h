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

	void LoginIn(string filename, int type);//��¼����

	void managerMenu(Identity*& manager);//����Ա�˵�

	void studentMenu(Identity*& student);//ѧ���˵�

	void teacherMenu(Identity*& teacher);//��ʦ�˵�

};
