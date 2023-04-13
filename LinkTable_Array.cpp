#include<iostream>
using namespace std;
template<class T>
class LinkTable_Array
{
public:
	LinkTable_Array();
	LinkTable_Array(int Size);
	~LinkTable_Array();
	void addElement(T element);
	void Insert(int position,T element); 
	void DeleteElem(int position);    //ɾ�������±��е�ʵ��ֵ
	T FindKth(int position);     //���ش�������������е�ֵ
	int Find(T element);         //�����ҵ�Ԫ�ص��±�
	bool isEmpty();
private:
	T* element_Array;            //ָ���ڴ��ַ��ָ��
	int ListSize = 0;    //��˳���ĳ���
	int Last=-1;
	
	//ָ��˳��������Ԫ�����   ��ʼΪ-1
};
template<class T>
LinkTable_Array<T>::LinkTable_Array()
{
	this->ListSize = INT_MAX;

	this->element_Array = new T[ListSize];
}
template<class T>
LinkTable_Array<T>::LinkTable_Array(int Size)
{
	this->element_Array = new T[Size];

	this->ListSize = Size;

	this->Last = -1;
}

template<class T>
LinkTable_Array<T>::~LinkTable_Array()
{
	delete(this->element_Array);
}

template<class T>
void LinkTable_Array<T>::addElement(T element)
{
	if (Last == (this->ListSize)-1)
	{
		//�ñ�����
		cout << "�ñ�����" << endl;
	}
	else
	{
		this->element_Array[++Last] = element;               //�ȶ�Last++���ٽ��и�ֵ����Last����һֱָ������һ��Ԫ��
	}
}

template<class T>
void LinkTable_Array<T>::Insert(int P,T Elem)
{
	if (this->Last == (this->ListSize)-1)
	{
		cout << "������" << endl;
		return;
	}
	if (P > this->ListSize)
	{
		cout << "���Ϸ���λ��" << endl;
		return;
	}
	//��Ҫ�Ե�postionλ��Ԫ�صĺ����Ԫ�ؽ��и�ֵ�ƶ����������󿴣���Ϊ�����һ��LastԪ�ؽ����ƶ�������position��λ��
	for (int now = this->Last; now >= P; --now)
	{
		this->element_Array[now + 1] = this->element_Array[now];

	}
	this->element_Array[P] = Elem;
}

template<class T>
void LinkTable_Array<T>::DeleteElem(int position)
{
	if (this->isEmpty)
	{
		return;
	}
	if (position > this->Last)
	{
		cout << "λ�ò��Ϸ�" << endl;

		return;
	}
	else
	{
		for (int i = position; i <= this->Last - 1; ++i)
		{
			this->element_Array[i] = this->element_Array[i + 1];
		}
	}
	--this->Last;
}

template<class T>
T LinkTable_Array<T>::FindKth(int position)
{
	if (this->element_Array == NULL)
	{
		return NULL;
	}
	if (position > this->Last)
	{
		cout << "���Ϸ���λ��" << endl;
	}
	else
	{
		return this->element_Array[position];
	}
}

template<class T>
int LinkTable_Array<T>::Find(T element)
{
	if (this->element_Array == NULL)
	{
		return -1;
	}
	else
	{
		int Ptrl = 1;     //ָ���һ��Ԫ��
		while (Ptrl <= this->Last && this->element_Array[Ptrl] != element)
		{
			Ptrl++;
		}
		if (Ptrl > this->Last)
		{
			return -1;
		}
		else
		{
			return Ptrl;
		}
	}
}
template<class T>
bool LinkTable_Array<T>::isEmpty()
{
	if (this->Last == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
