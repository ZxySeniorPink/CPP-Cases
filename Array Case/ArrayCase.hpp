#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Array
{
public:
	//构造函数
	Array() {}
	Array(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_size = 0;
		p_Array = new T[this->m_Capacity];
	}

	//拷贝构造
	Array(const Array& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->p_Array = new T[this->m_Capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			//如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是构造 而是赋值
			//普通类型可以直接 = 但是指针来行需要深拷贝
			this->p_Array[i] = arr.p_Array[i];
		}
	}

	//重载 = 操作符 防止浅拷贝问题
	Array& operator=(const Array& arr)
	{
		if (this->p_Array != NULL)
		{
			delete[] this->p_Array;
			this->m_Capacity = 0;
			this->m_size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->p_Array = new T[this->Capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->p_Array[i] = arr[i];
		}
		return *this;
	}

	//重载 [] 操作符
	T& operator[](int index)
	{
		return this->p_Array[index];//没有考虑越界，用户自己去处理
	}

	//尾插法
	void PushBack(const T& val)
	{
		if (this->m_Capacity == this->m_size)
		{
			return;
		}
		this->p_Array[this->m_size] = val;
		this->m_size++;
	}

	//尾删法
	void PopBack()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}

	//获取数组容量
	int GetCapacity()
	{
		return this->m_Capacity;
	}

	//获取数组大小
	int GetSize()
	{
		return this->m_size;
	}

	//析构函数
	~Array()
	{
		if (this->p_Array != NULL)
		{
			delete[] this->p_Array;
			this->p_Array = NULL;
			this->m_Capacity = 0;
			this->m_size = 0;
		}
	}


private:
	T* p_Array; //指向一个堆空间，这个空间储存真正的数据
	int m_Capacity;//容量
	int m_size;//数组实际大小
};