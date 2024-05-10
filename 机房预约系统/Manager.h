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
	Manager();//Ĭ�Ϲ���

	Manager(string name,string pwd);//�вι���

	virtual void operMenu();//����Ա�˵�

	void addPerson();//����˺�

	void showPerson();//�鿴�˺�

	void showComputer();//�鿴������Ϣ

	void cleanFile();//���ԤԼ��¼

	void initVector();//��ʼ������

	void initComVector();//��ʼ����������

	vector<Student>vStu;//ѧ������

	vector<Teacher>vTea;//��ʦ����

	vector<ComputerRoom>vCom;//������Ϣ����
};
