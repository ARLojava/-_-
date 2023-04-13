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
	void DeleteElem(int position);    //删除数组下标中的实际值
	T FindKth(int position);     //返回传入参数在数组中的值
	int Find(T element);         //返回找到元素的下标
	bool isEmpty();
private:
	T* element_Array;            //指向内存地址的指针
	int ListSize = 0;    //其顺序表的长度
	int Last=-1;
	
	//指向顺序表的最后的元素序号   初始为-1
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
		//该表已满
		cout << "该表已满" << endl;
	}
	else
	{
		this->element_Array[++Last] = element;               //先对Last++，再进行赋值，则Last将会一直指向最后的一个元素
	}
}

template<class T>
void LinkTable_Array<T>::Insert(int P,T Elem)
{
	if (this->Last == (this->ListSize)-1)
	{
		cout << "表已满" << endl;
		return;
	}
	if (P > this->ListSize)
	{
		cout << "不合法的位置" << endl;
		return;
	}
	//将要对第postion位个元素的后面的元素进行赋值移动，从右往左看，即为从最后一个Last元素进行移动至现在position的位置
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
		cout << "位置不合法" << endl;

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
		cout << "不合法的位置" << endl;
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
		int Ptrl = 1;     //指向第一个元素
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
