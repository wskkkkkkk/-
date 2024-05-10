#include"Order.h"




Order::Order() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	
	string data;
	string time;
	string roomId;
	string stuId;
	string stuName;
	string status;

	this->m_Size = 0;
	while (ifs >> data && ifs >> time && ifs >> roomId && ifs >> stuId && ifs >> stuName && ifs >> status) {
		//data:1
		string key;
		string value;
		map<string, string>m;
		int pos = data.find(":");
		key = data.substr(0, pos);
		value = data.substr(pos + 1, data.size() - pos - 1);
		m.insert(make_pair(key, value));
		
		pos = time.find(":");
		key = time.substr(0, pos);
		value = time.substr(pos + 1, time.size() - pos - 1);
		m.insert(make_pair(key, value));
		
		pos = roomId.find(":");
		key = roomId.substr(0, pos);
		value = roomId.substr(pos + 1, roomId.size() - pos - 1);
		m.insert(make_pair(key, value));
	
		pos = stuId.find(":");
		key = stuId.substr(0, pos);
		value = stuId.substr(pos + 1, stuId.size() - pos - 1);
		m.insert(make_pair(key, value));
	
		pos = stuName.find(":");
		key = stuName.substr(0, pos);
		value = stuName.substr(pos + 1, stuName.size() - pos - 1);
		m.insert(make_pair(key, value));
		
		pos = status.find(":");
		key = status.substr(0, pos);
		value = status.substr(pos + 1, status.size() - pos - 1);
		m.insert(make_pair(key, value));
	
		m_Size++;
		this->m_orderDate.insert(make_pair(this->m_Size, m));
	}
	
	ifs.close();

}



void Order::updateOder() {
	ofstream ofs;
	if (this->m_Size == 0) {
		return;
	}
	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 1; i <= this->m_Size; i++) {
		ofs << "data:" << this->m_orderDate[i]["data"] << " ";
		ofs << "time:" << this->m_orderDate[i]["time"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << endl;
	}
	ofs.close();
}
