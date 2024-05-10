#pragma once
#include"Identity.h"
#include"ComputerRoom.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include"Order.h"
class Student : public Identity {
public:
	Student();
	Student(int id, string name, string pwd);
	virtual void operMenu();

	void InitComputerRoomVector();//初始化机房容器

	void applyOrder();//申请预约

	void showMyOrder();//查看我的预约

	void showAllOrder();//查看所有预约

	void cancelOrder();//取消预约

	int m_Id;

	vector<ComputerRoom>vCom;//机房信息
};