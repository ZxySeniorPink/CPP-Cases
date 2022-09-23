#include <iostream>
#include <string>
#include <list>

using namespace std;

class Person
{
public:

	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

public:

	string m_Name;
	int m_Age;
	int m_Height;
};

bool ComparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}

void test()
{
	list<Person> L;

	Person p1 = { "LUFFY", 19, 170 };
	Person p2 = { "ZORO", 21, 180 };
	Person p3 = { "SANJI", 19 , 177 };
	Person p4 = { "NAMI", 20, 165 };
	Person p5 = { "USOPP", 19, 175 };
	Person p6 = { "CHOPPER", 17, 50 };

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "Name: " << it->m_Name << "\tAge: " << it->m_Age << "\tHeight: " << it->m_Height << endl;
	}

	L.sort(ComparePerson);
	cout << "\nAfter Sort-------------------------\n" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "Name: " << it->m_Name << "\tAge: " << it->m_Age << "\tHeight: " << it->m_Height << endl;
	}
}

int main()
{
	test();

	system("pause");
	return 0;
}