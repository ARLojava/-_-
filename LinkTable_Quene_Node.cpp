#include<iostream>
typedef struct QNode* Queue;
struct LinkTable_Queue_Node
{
	LinkTable_Queue_Node* next;
	int Value;
};
struct QNode
{
	LinkTable_Queue_Node* Front;
	LinkTable_Queue_Node* Rear;
};
Queue CreatQueue()
{
	Queue Q;
	Q = new QNode;
	Q->Front = NULL;
	Q->Rear = NULL;
	return Q;
}
bool isEmpty(Queue Q)
{
	return Q->Front == NULL;
}
void addElemnt(Queue Q, int Element)
{
	LinkTable_Queue_Node* Node = new LinkTable_Queue_Node;
	Node->Value = Element;
	Node->next = NULL;
	if (isEmpty)
	{
		//�������Ϊ��   �򽫶��е�ͷָ����βָ��ָ��ô��ڵ�
		Q->Front = Node;
		Q->Rear = Node;
	}
	else
	{
		//��ʱ���в�Ϊ�� ��βָ��˳�������ƶ�   == �����β��ӽڵ�
		Q->Rear->next = Node;
		Q->Rear = Q->Rear->next;
	}
}
int DeleteElement(Queue Q)
{
	//ɾ��ͷָ����ָ���Ԫ��    ���е��Ƚ��ȳ�����
	LinkTable_Queue_Node* Ptrl = Q->Front;
	if (isEmpty(Q))
	{
		//����Ϊ�յĻ�
		return -1;
	}
	if (Q->Front == Q->Rear)
	{
		//��ʱ������ֻ��һ��Ԫ��
		Q->Front = NULL;
		Q->Rear = NULL;
		return Ptrl->Value;
	}
	else
	{
		//�ƶ�ͷָ��
		Q->Front = Q->Front->next;
		int returnData = Ptrl->Value;
		delete Ptrl;
		return returnData;
	}
}