#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Array
{
public:
	//���캯��
	Array() {}
	Array(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_size = 0;
		p_Array = new T[this->m_Capacity];
	}

	//��������
	Array(const Array& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->p_Array = new T[this->m_Capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			//���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��ǹ��� ���Ǹ�ֵ
			//��ͨ���Ϳ���ֱ�� = ����ָ��������Ҫ���
			this->p_Array[i] = arr.p_Array[i];
		}
	}

	//���� = ������ ��ֹǳ��������
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

	//���� [] ������
	T& operator[](int index)
	{
		return this->p_Array[index];//û�п���Խ�磬�û��Լ�ȥ����
	}

	//β�巨
	void PushBack(const T& val)
	{
		if (this->m_Capacity == this->m_size)
		{
			return;
		}
		this->p_Array[this->m_size] = val;
		this->m_size++;
	}

	//βɾ��
	void PopBack()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}

	//��ȡ��������
	int GetCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int GetSize()
	{
		return this->m_size;
	}

	//��������
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
	T* p_Array; //ָ��һ���ѿռ䣬����ռ䴢������������
	int m_Capacity;//����
	int m_size;//����ʵ�ʴ�С
};