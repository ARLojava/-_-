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
		//如果队列为空   则将队列的头指针与尾指针指向该处节点
		Q->Front = Node;
		Q->Rear = Node;
	}
	else
	{
		//此时队列不为空 则将尾指针顺序往后移动   == 链表的尾添加节点
		Q->Rear->next = Node;
		Q->Rear = Q->Rear->next;
	}
}
int DeleteElement(Queue Q)
{
	//删除头指针所指向的元素    队列的先进先出性质
	LinkTable_Queue_Node* Ptrl = Q->Front;
	if (isEmpty(Q))
	{
		//队列为空的话
		return -1;
	}
	if (Q->Front == Q->Rear)
	{
		//此时队列中只有一个元素
		Q->Front = NULL;
		Q->Rear = NULL;
		return Ptrl->Value;
	}
	else
	{
		//移动头指针
		Q->Front = Q->Front->next;
		int returnData = Ptrl->Value;
		delete Ptrl;
		return returnData;
	}
}