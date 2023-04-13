#include<iostream>
using namespace std;
class Stack_data
{
public:
	void Push(int element);
	int Pop();
	bool isEmpty();
	Stack_data();
	~Stack_data();

private:
	int* Stack_Array;
	int Size;
	int Top = -1;
};

void Stack_data::Push(int element)
{
	if (this->Top != this->Size )
	{
		this->Stack_Array[++Top] = element;
	}
}

int Stack_data::Pop()
{
	if (this->isEmpty())
	{
		return -1;
	}
	else
	{
		int data = this->Stack_Array[Top--];
		return data;
	}
}

bool Stack_data::isEmpty()
{
	return this->Top == -1;
}

Stack_data::Stack_data()
{
	this->Stack_Array = new int[16];
	this->Size = 16;
	this->Top = -1;
}

Stack_data::~Stack_data()
{
	delete this->Stack_Array;
	this->Size = 0;
	this->Top = -1;
}