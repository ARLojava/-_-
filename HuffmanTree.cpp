#include<iostream>
#include<queue>
#include<algorithm>

void Heapifiy(int* &arr, int index, int size);
void HeapInsert(int* &arr, int Size);
void Swap(int*& arr, int p1, int p2);
using namespace std;
struct TreeNode_HuffMan
{
	int Value;
	TreeNode_HuffMan* Left;
	TreeNode_HuffMan* Right;
	TreeNode_HuffMan();
	TreeNode_HuffMan(int Weight);
};
class MinHeap
{
public:
	void LevelOrderTravel();
	int DeleteMin();
	void Create(int* arr, int size);
	void Create(int MaxSize);
	bool isEmpty();
	bool isFull();
	int* getElement();
	friend void Swap(int*& arr, int p1, int p2);
	void Insert(int item);
	MinHeap();
	~MinHeap();
	int getSize();

private:
	friend void Heapifiy(int*& arr, int index, int size);
	void DeepCopy();
	friend void HeapInsert(int*& array, int Size);
	int* elmentArray;
	int Size;
	int Capicity;
};
class HuffManTree
{
public:
	HuffManTree();
	~HuffManTree();
	void LevelOrderTravel();
	TreeNode_HuffMan* getRoot();
	void CreateHuffMan(int* array,int Size);

private:
	friend void Heapifiy(int*& arr, int index, int size);
	friend void HeapInsert(int*& arr, int Size);
	TreeNode_HuffMan* root;
	TreeNode_HuffMan* Insert_CreateHuffMan();
	int Size;
	MinHeap* MH;
};

void MinHeap::LevelOrderTravel()
{
 	for (int index = 0; index < this->Size; ++index)
	{
 		cout << this->elmentArray[index] << " ";
	}
	cout << endl;
 }

int MinHeap::DeleteMin()
{
	int root = this->elmentArray[0];
	for (int index = 1; index < this->Size; ++index)
	{
		this->elmentArray[index - 1] = this->elmentArray[index];
	}
	--this->Size;
	for (int index = 0; index < this->Size; ++index)
	{
		HeapInsert(this->elmentArray, index);
	}
	return root;
}

void MinHeap::Create(int* arr, int size)
{
	if (this->Capicity < size)
	{
		this->Capicity = size;
		this->elmentArray = new int[Capicity];
	}
	for (int index = 0; index < size; ++index)
	{
		this->elmentArray[index] = arr[index];
		this->Size++;
		HeapInsert(this->elmentArray, index);
	}
	
}

void MinHeap::Create(int MaxSize)
{
	if (this->Capicity < MaxSize)
	{
		this->Capicity = MaxSize;
		this->elmentArray = new int[MaxSize];
	}
	for (int index = 0; index < MaxSize; ++index)
	{
		cin >> this->elmentArray[index];
	}
}

bool MinHeap::isEmpty()
{
	if (this->elmentArray != NULL)
	{
		return this->Size == 0;
	}
	return false;
}

bool MinHeap::isFull()
{
	if (this->elmentArray != NULL)
	{
		return this->Size == this->Capicity ;
	}
	return false;
}

int* MinHeap::getElement()
{
	if (this->elmentArray != NULL)
	{
		return this->elmentArray;
	}
	return nullptr;
}

void MinHeap::Insert(int item)
{
	if (this->elmentArray == NULL)
	{
		return;
	}
	if (this->isFull())
	{
		this->DeepCopy();
	}
	this->elmentArray[Size] = item;
	HeapInsert(this->elmentArray, this->Size);
	++Size;
}

MinHeap::MinHeap()
{
	this->elmentArray = new int[5];
	this->Size = 0;
	this->Capicity = 5;
}

MinHeap::~MinHeap()
{
	fill(this->elmentArray, this->elmentArray + this->Size, 0);
	this->Size = 0;
	this->Capicity = 0;
}
int MinHeap::getSize()
{
	return this->Size;
}
void MinHeap::DeepCopy()
{
	this->Capicity *= 2;
	int* _newtemp = new int[Capicity];
	for (int index = 0; index < this->Size; ++index)
	{
		_newtemp[index] = this -> elmentArray[index];
	}
	delete elmentArray;
	elmentArray = _newtemp;
}
HuffManTree::HuffManTree()
{
	this->root = NULL;
	this->Size = NULL;
	this->MH = nullptr;
}

HuffManTree::~HuffManTree()
{
	TreeNode_HuffMan* Ptrl = this->root;
	queue<TreeNode_HuffMan*>* Q = new queue<TreeNode_HuffMan*>();
	if (Ptrl != NULL) Q->push(Ptrl);
	while (!Q->empty())
	{
		Ptrl = Q->front();
		Q->pop();
		if (Ptrl->Left != NULL) Q->push(Ptrl->Left);
		if (Ptrl->Right != NULL) Q->push(Ptrl->Right);
		delete Ptrl;
	}
	this->Size = 0;
	delete Q;
}

void HuffManTree::LevelOrderTravel()
{
	queue<TreeNode_HuffMan*>* Q = new queue<TreeNode_HuffMan*>();
	Q->push(this->root);
	while (!Q->empty())
	{
		TreeNode_HuffMan* Ptrl = Q->front();
		if (Ptrl->Left != NULL) Q->push(Ptrl->Left);
		if (Ptrl->Right != NULL) Q->push(Ptrl->Right);
		cout << Ptrl->Value << " ";
		Q->pop();
	}
}

void HuffManTree::CreateHuffMan(int* array, int size)
{
	MinHeap* heap = new MinHeap();
	heap->Create(array, size);
	this->MH = heap;
	//this->Aux_CreateHuffMan();
	this->root=Insert_CreateHuffMan();
	queue<TreeNode_HuffMan*>* UnLinkNode =new queue<TreeNode_HuffMan*>();
	while (!(MH->getSize()==1))
	{
		TreeNode_HuffMan* _Insert_Tree = Insert_CreateHuffMan();
		//都不是则应该将该节点进行存储应为先进先出的模式
		if(_Insert_Tree->Left->Value!=this->root->Value&& _Insert_Tree->Right->Value != this->root->Value)
		UnLinkNode->push(_Insert_Tree);
		if (_Insert_Tree->Left->Value == this->root->Value)
		{
			//为左子树的孩子
			_Insert_Tree->Left = this->root;
			this->root = _Insert_Tree;

		}
		if (_Insert_Tree->Right->Value == this->root->Value)
		{
			//为右子树的孩子
			_Insert_Tree->Right = this->root;
			this->root = _Insert_Tree;
		}
		if (!UnLinkNode->empty())
		{
			TreeNode_HuffMan* Temp = UnLinkNode->front();
			if (Temp->Value <= this->root->Value)
			{
				int sum = Temp->Value + this->root->Value;
				TreeNode_HuffMan* data =new TreeNode_HuffMan(sum);
				data->Left = this->root;
				data->Right = Temp;
				UnLinkNode->pop();
			}
		}
	}
	MH->DeleteMin();
}

TreeNode_HuffMan* HuffManTree::Insert_CreateHuffMan()
{
	if (this->MH->isEmpty())
	{
		return nullptr;
	}
	int _first = this->MH->DeleteMin();
	int _second = this->MH->DeleteMin();
	int sum = _first + _second;
	MH->Insert(sum);
	TreeNode_HuffMan* Left = new TreeNode_HuffMan(_first);
	TreeNode_HuffMan* Right = new TreeNode_HuffMan(_second);
	TreeNode_HuffMan* root = new TreeNode_HuffMan(sum);
	root->Left = Left;
	root->Right = Right;
	return root;
}

TreeNode_HuffMan::TreeNode_HuffMan()
{
	this->Value = 0;
	this->Left = nullptr;
	this->Right = nullptr;
}

TreeNode_HuffMan::TreeNode_HuffMan(int Weight)
{
	this->Value = Weight;
	this->Left = NULL;
	this->Right = NULL;
}

void Swap(int*& arr, int p1, int p2)
{
	if (arr == NULL)
	{
		return;
	}
	int Temp = arr[p2];
	arr[p2] = arr[p1];
	arr[p1] = Temp;
}


void Heapifiy(int*& arr, int index, int size)
{
	if (arr == NULL)
	{
		return;
	}
	int Left = index * 2 + 1;
	while (Left < size)
	{
		int Minist = arr[Left] < arr[Left + 1] && Left + 1 < size ? Left : Left + 1;
		Minist = arr[Minist] < arr[index] ? Minist :index;
		if (Minist == index)
		{
			break;
		}
		Swap(arr, Minist, index);
		index = Minist;
		Left = index * 2 + 1;
	}
}

void HeapInsert(int*& array, int Position)
{
	int Parent = (Position - 1) / 2;
	while (array[Parent]>array[Position])
	{
		Swap(array, Parent, Position);
		Position = Parent;
		Parent= (Position - 1) / 2;
	}
}