#include<iostream>
using namespace std;
struct Node
{
	int coeffcient;
	int exponent;
	Node* next;
};
Node* InitPolynomial()
{
	int control = 0;
	Node*  head = new Node;
	Node* Ptrl = head;
	cout << "输入该多项式的项数" << endl;
	cin >> control;
	while (control--)
	{
		Node* Temp = new Node;
		cin >> Temp->coeffcient;
		cin >> Temp->exponent;
		Temp->next = NULL;
		Ptrl->next = Temp;
		Ptrl = Temp;
	}
	Ptrl->next = NULL;
	Node* First = head;
	head = head->next;
	delete First;
	return head;
}
void PrintPolynomial(Node* s1)
{
	Node* Ptrl = s1;
	while (Ptrl)
	{
		cout << Ptrl->coeffcient << "  " << Ptrl->exponent << endl;
		Ptrl = Ptrl->next;
	}
}
int Campare(Node* h1,Node* h2)
{
	if (h1->exponent < h2->exponent) return -1;

	else if (h1->exponent == h2->exponent)  return 0;

	else return 1;
}
Node* Polynomial_add(Node* head1, Node* head2)
{
	Node* Ptrl_h1 = head1;
	Node* Ptrl_h2 = head2;
	Node* Ptrl_Temp = new Node;
	Node* result = Ptrl_Temp;
	while (Ptrl_h1 && Ptrl_h2)
	{
		Node* temp = new Node;
		//他们之中有一个不为空
		//head1 的系数大于 head2的系数   head2的内容写入result  移动head2
		//head1 的系数等于 head2的系数   只有这块地方需要相加  两个指针同时移动
		//head1 的系数小于 head2的系数    head1的内容写入result 移动head1
		switch (Campare(Ptrl_h1,Ptrl_h2))
		{
		case -1:
			//head1 的系数小于 head2的系数    head1的内容写入result 移动head1
			temp->coeffcient = Ptrl_h1->coeffcient;
			temp->exponent = Ptrl_h1->exponent;
			temp->next = NULL;
			Ptrl_Temp->next=temp;
			Ptrl_Temp = Ptrl_Temp->next;
			Ptrl_h1 = Ptrl_h1->next;
			break;

		case 0:
			//head1 的系数等于 head2的系数   只有这块地方需要相加  两个指针同时移动
			if (Ptrl_h1->coeffcient + Ptrl_h2->coeffcient != 0)
			{
				temp->coeffcient = Ptrl_h1->coeffcient + Ptrl_h2->coeffcient;
				temp->exponent = Ptrl_h1->exponent;
				temp->next = NULL;
				Ptrl_Temp->next=temp;
				Ptrl_Temp = Ptrl_Temp->next;
			}
			Ptrl_h1 = Ptrl_h1->next;
			Ptrl_h2 = Ptrl_h2->next;
			break;
		case 1:
			//head1 的系数大于 head2的系数   head2的内容写入result  移动head2
			temp->coeffcient = Ptrl_h2->coeffcient;
			temp->exponent = Ptrl_h2->exponent;
			temp->next = NULL;
			Ptrl_Temp->next = temp;
			Ptrl_Temp = Ptrl_Temp->next;
			Ptrl_h2 = Ptrl_h2->next;
			break;
		}
	}
	while (Ptrl_h1)
	{
		Node* Temp = new Node;
		Temp->coeffcient = Ptrl_h1->coeffcient;
		Temp->exponent = Ptrl_h1->exponent;
		Temp->next = NULL;
		Ptrl_Temp->next = Temp;
		Ptrl_Temp = Ptrl_Temp->next;
		Ptrl_h1 = Ptrl_h1->next;
	}
	while (Ptrl_h2)
	{
		Node* Temp = new Node;
		Temp->coeffcient = Ptrl_h2->coeffcient;
		Temp->exponent = Ptrl_h2->exponent;
		Temp->next = NULL;
		Ptrl_Temp->next = Temp;
		Ptrl_Temp = Ptrl_Temp->next;
		Ptrl_h2 = Ptrl_h2->next;
	}
	Node* detail = result;
	result = result->next;
	delete detail;
	return result;
}
int main()
{
	Node* s1 = InitPolynomial();
	Node* s2 = InitPolynomial();

	Node* ans=Polynomial_add(s1, s2);

	PrintPolynomial(ans);
}
