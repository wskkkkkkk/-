#pragma once
#include"Identity.h"
#include"Order.h"
#include<vector>
class Teacher : public Identity {
public:
	Teacher();

	Teacher(int empid,string name,string pwd);//�вι���

	virtual void operMenu();//��ʦ�˵���ʾ

	void showAllOrder();//��ʾ���е�ԤԼ����

	void vaildOrder();//���ԤԼ

	int empId;

};