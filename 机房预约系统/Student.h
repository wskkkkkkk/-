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

	void InitComputerRoomVector();//��ʼ����������

	void applyOrder();//����ԤԼ

	void showMyOrder();//�鿴�ҵ�ԤԼ

	void showAllOrder();//�鿴����ԤԼ

	void cancelOrder();//ȡ��ԤԼ

	int m_Id;

	vector<ComputerRoom>vCom;//������Ϣ
};