#include<iostream>
class queue
{
public:
	void addElement(int Data);
	int DeleteElement();
	bool isEmpty();
	bool isFull();
	queue();
	~queue();

private:
	int* Array;
	int Front;
	int Rear;
	int Size;
};
void queue::addElement(int Value)
{
	if (isFull)
	{
		return;
	}
	else
	{
		this->Rear = (this->Rear + 1) % Size;
	}
}
int queue::DeleteElement()
{
	if (!this->isEmpty())
	{
		this->Front=(this->Front + 1) % Size;
		return Array[Front];
	}
	else
	{
		return 0;
	}
}
bool queue::isEmpty()
{
	return this->Front == this->Rear;
}
bool queue::isFull()
{
	return (this->Front + 1) % Size == this->Front;
}
queue::queue()
{
	this->Size = 16;
	this->Array = new int[Size];
	this->Front = 0;
	this->Rear = 0;
}

queue::~queue()
{
	delete this->Array;
	this->Front = 0;
	this->Rear = 0;
	this->Size = 0;
}