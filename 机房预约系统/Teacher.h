#pragma once
#include"Identity.h"
#include"Order.h"
#include<vector>
class Teacher : public Identity {
public:
	Teacher();

	Teacher(int empid,string name,string pwd);//有参构造

	virtual void operMenu();//教师菜单显示

	void showAllOrder();//显示所有的预约申请

	void vaildOrder();//审核预约

	int empId;

};