#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#define Dept1 1
#define Dept2 2
#define Dept3 3

using namespace std;

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void CreateWorker(vector<Worker>& v)
{
	string name_seed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Worker";
		worker.m_Name += name_seed[i];
		worker.m_Salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}

void SetGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int dep_id = rand() % 3 + 1; //1 2 3

		//将员工插入到分组种
		m.insert(make_pair(dep_id, *it));
	}
}

void ShowWorkersByGroup(multimap<int, Worker>& m)
{
	cout << "Dept1:" << endl;
	multimap<int, Worker>::iterator it = m.begin();
	for (; it != m.find(2); it++)
	{
		cout << "Name: " << it->second.m_Name << " Salary: " << it->second.m_Salary << endl;
	}
	cout << "------------------------------" << endl;

	cout << "Dept2:" << endl;
	for (; it != m.find(3); it++)
	{
		cout << "Name: " << it->second.m_Name << " Salary: " << it->second.m_Salary << endl;
	}
	cout << "------------------------------" << endl;

	cout << "Dept3:" << endl;
	for (; it != m.end(); it++)
	{
		cout << "Name: " << it->second.m_Name << " Salary: " << it->second.m_Salary << endl;
	}
	cout << "------------------------------" << endl;

}

int main()
{
	srand((unsigned int)time(NULL));

	vector<Worker> worker;
	CreateWorker(worker);

	multimap<int, Worker> m_worker;
	SetGroup(worker, m_worker);

	ShowWorkersByGroup(m_worker);

	system("pause");
	return 0;
}