#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:

	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};


//����ѡ��
void CreatePerson(vector<Person>& persons)
{
	string name_seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += name_seed[i];

		int score = 0;

		Person p(name, score);

		persons.push_back(p);
	}
}

//��ί���
void GetScore(vector<Person>& persons)
{
	for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++)
	{
		//����ί�ķ������뵽deque������
		deque<int> points;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			points.push_back(score);
		}

		//cout << "ѡ�֣�" << it->m_Name << " �÷�Ϊ��" << endl;
		//for (deque<int>::iterator point_it = points.begin(); point_it != points.end(); point_it++)
		//{
		//	cout << *point_it << " ";
		//}

		//����
		sort(points.begin(), points.end());

		//ȥ����߷ֺ���ͷ�
		points.pop_back();
		points.pop_front();

		//ƽ����
		int sum = 0;
		for (deque<int>::iterator point_it = points.begin(); point_it != points.end(); point_it++)
		{
			sum += *point_it;//�ۼ�ÿ������
		}
		int avg = sum / points.size();

		//��ƽ���ָ�ֵ��ѡ������
		it->m_Score = avg;
	}

}

void ShowScore(vector<Person>& persons)
{
	for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++)
	{
		cout << "Name: " << it->m_Name << " Score: " << it->m_Score << endl;
	}
}

int main()
{
	//���������
	srand((unsigned int)time(NULL));
	vector<Person> persons;

	//����ѡ��
	CreatePerson(persons);

	//����
	/*for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++)
	{
		cout << "ѡ��������" << it->m_Name << " ������" << it->m_Score << endl;
	}*/

	//��ί���
	GetScore(persons);

	//չʾ����
	ShowScore(persons);

	system("pause");
	return 0;
}