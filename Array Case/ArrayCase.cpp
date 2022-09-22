#include "ArrayCase.hpp"

void PrintIntArray(Array<int>& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test01()
{
	Array<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.PushBack(i);
	}
	cout << "array1 output: " << endl;
	PrintIntArray(array1);
	
	cout << "\narray1's size: " << array1.GetSize() << endl;
	cout << "array1's Capacity: " << array1.GetCapacity() << endl;
	cout << "---------------------------------------" << endl;

	Array<int> array2 = array1;
	
	array2.PopBack();
	cout << "array2's output:" << endl;
	PrintIntArray(array2);

	cout << "\narray2's size: " << array2.GetSize() << endl;
	cout << "array2's Capacity: " << array2.GetCapacity() << endl;
	cout << "---------------------------------------" << endl;
}

class Person
{
public:
	Person() {}
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	int m_Age;
	string m_Name;
};

void PrintPersonArray(Array<Person>& persons)
{
	for (int i = 0; i < persons.GetSize(); i++)
	{
		cout << "Person's name: " << persons[i].m_Name << "\tage: " << persons[i].m_Age << endl;
	}
}

//测试自定义数据类型
void test02()
{
	Array<Person> persons(12);
	Person p1("MONKEY·D·LUFFY", 19);
	Person p2("RORONOA ZORO", 21);
	Person p3("VINSMOKE SANJI", 19);
	Person p4("NAMI", 20);
	Person p5("USOPP", 19);
	Person p6("CHOPPER",17);
	Person p7("NICO ROBIN", 30);
	Person p8("FRANKY", 36);
	Person p9("BROOK", 90);
	Person p10("JINBE", 46);
	Person p11("VIVI", 18);
	Person p12("YAMATO", 28);

	persons.PushBack(p1);
	persons.PushBack(p2);
	persons.PushBack(p3);
	persons.PushBack(p4);
	persons.PushBack(p5);
	persons.PushBack(p6);
	persons.PushBack(p7);
	persons.PushBack(p8);
	persons.PushBack(p9);
	persons.PushBack(p10);
	persons.PushBack(p11);
	persons.PushBack(p12);
	
	PrintPersonArray(persons);

	
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

