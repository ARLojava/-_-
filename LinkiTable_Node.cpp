#include<iostream>
using namespace std;
struct Node
{
	string Value;
	Node* next;
};
class LinkTable
{
public:
	void Frontadd(string item);
	void Rearadd(string item);
	void display();
	void Insert(int position,string item);
	void Delete_Node(int position);
	void Serach(int position);
	int Serach(string item);
	int Length();
	LinkTable();
	~LinkTable();

private:
	Node* head;
	int Size;
};

LinkTable::LinkTable()
{
	this->head = NULL;
	this->Size = 0;
}

LinkTable::~LinkTable()
{
	Node* Ptrl = this->head;
	while (Ptrl->next)
	{
		Node* temp = Ptrl->next;
		delete Ptrl;
		Ptrl = temp;
	}
	delete Ptrl;
}

void LinkTable::Frontadd(string item)
{
	if (this->head == NULL)
	{
		this->head = new Node;
		this->head->Value = item;
		this->head->next = NULL;
		this->Size++;
	}
	else 
	{
		Node* temp = new Node;
		temp->Value = item;
		temp->next = this->head;
		this->head = temp;
		this->Size++;
	}
}
void LinkTable::display()
{
	Node* Ptrl = this->head;
	while (Ptrl)
	{
		cout << Ptrl->Value << endl;
		Ptrl = Ptrl->next;
	}
}
void LinkTable::Insert(int position, string item)
{
	Node* Ptrl = this->head;
	for (int i = 0; i != position - 1; ++i)
	{
		Ptrl = Ptrl->next;
	}
	Node* temp = new Node;
	temp->Value = item;
	temp->next = Ptrl->next;
	Ptrl->next = temp;
	this->Size++;
}
void LinkTable::Delete_Node(int position)
{
	Node* Ptrl = this->head;
	for (int i = 0; i != position - 1; ++i)
	{
		Ptrl = Ptrl->next;
	}
	Node* temp = Ptrl->next;
	Ptrl->next = temp->next;
	delete temp;
	--this->Size;
}
void LinkTable::Serach(int position)
{
	if (position >= this->Size || this->head == NULL)
	{
		return;
	}
	Node* Ptrl = this->head;
	for (int i = 0; i != position; ++i)
	{
		Ptrl = Ptrl->next;
	}
	cout << Ptrl->Value << endl;
}
int LinkTable::Serach(string item)
{
	int i = 0;
	Node* Ptrl = this->head;
	while (Ptrl->next != NULL && Ptrl->Value != item)
	{
		Ptrl = Ptrl->next;
		++i;
	}
	if (Ptrl->next == NULL)
	{
		return -1;
	}
	return i;
}
int LinkTable::Length()
{
	if (this->head == NULL)
	{
		return -1;
	}
	Node* Ptrl = this->head;
	int Length = 1;
	while (Ptrl->next!=NULL)
	{
		Ptrl = Ptrl->next;
		++Length;
	}
	return Length;
}
void LinkTable::Rearadd(string item)
{
	if (this->head == NULL)
	{
		this->head = new Node;
		head->Value = item;
		head->next = NULL;
		this->Size++;
	}
	else
	{
		Node* Ptrl = this->head;
		while (Ptrl->next)
		{
			Ptrl = Ptrl->next;
		}
		Node* temp = new Node;
		temp->Value = item;
		temp->next = NULL;
		Ptrl->next = temp;
		this->Size++;
	}
}