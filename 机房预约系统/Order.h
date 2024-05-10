#pragma once
#include<iostream>
#include"globalFile.h"
#include<map>
#include<fstream>
using namespace std;



class Order {
public:
	Order();
	void updateOder();

	map<int, map<string, string>>m_orderDate;
	
	int m_Size;
};