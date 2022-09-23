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


//创建选手
void CreatePerson(vector<Person>& persons)
{
	string name_seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += name_seed[i];

		int score = 0;

		Person p(name, score);

		persons.push_back(p);
	}
}

//评委打分
void GetScore(vector<Person>& persons)
{
	for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++)
	{
		//将评委的分数放入到deque容器中
		deque<int> points;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			points.push_back(score);
		}

		//cout << "选手：" << it->m_Name << " 得分为：" << endl;
		//for (deque<int>::iterator point_it = points.begin(); point_it != points.end(); point_it++)
		//{
		//	cout << *point_it << " ";
		//}

		//排序
		sort(points.begin(), points.end());

		//去掉最高分和最低分
		points.pop_back();
		points.pop_front();

		//平均分
		int sum = 0;
		for (deque<int>::iterator point_it = points.begin(); point_it != points.end(); point_it++)
		{
			sum += *point_it;//累加每个分数
		}
		int avg = sum / points.size();

		//将平均分赋值给选手身上
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
	//种随机种子
	srand((unsigned int)time(NULL));
	vector<Person> persons;

	//创建选手
	CreatePerson(persons);

	//测试
	/*for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++)
	{
		cout << "选手姓名：" << it->m_Name << " 分数：" << it->m_Score << endl;
	}*/

	//评委打分
	GetScore(persons);

	//展示分数
	ShowScore(persons);

	system("pause");
	return 0;
}