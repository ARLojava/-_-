#include<iostream>
using namespace std;
struct Node
{
	int Value;
	Node* next;
};
class Stack_Node
{
public:
	void Push(int Element);
	int Pop();
	bool isEmpty();
	Stack_Node();
	Stack_Node(int Element);
	~Stack_Node();

private:
	Node* head;
	int Length = 0;
};

void Stack_Node::Push(int data)
{
	if (this->head == NULL)
	{
		Node* temp = new Node;
		temp->next = NULL;
		temp->Value = data;
		this->head = temp;
		this->Length++;
	}
	else
	{
		Node* temp = new Node;
		temp->next = head;
		temp->Value = data;
		this->head = temp;
		this->Length++;
	}
}

int Stack_Node::Pop()
{
	if (!isEmpty())
	{
		Node* Ptrl = this->head;
		int data = Ptrl->Value;
		this->head = Ptrl->next;
		delete Ptrl;
		return data;
		this->Length--;
	}
	else
	{
		return -1;
	}
}

bool Stack_Node::isEmpty()
{
	if (this->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Stack_Node::Stack_Node()
{
	this->head = NULL;
	this->Length = 0;
}

Stack_Node::Stack_Node(int Element)
{
	Node* temp = new Node;
	temp->Value = Element;
	temp->next = NULL;
	this->head = temp;
}

Stack_Node::~Stack_Node()
{
	Node* PtrL = this->head;
	while (PtrL->next != NULL)
	{
		Node* temp = PtrL->next;
		delete PtrL;
		PtrL = temp;
	}
	delete PtrL;
}
