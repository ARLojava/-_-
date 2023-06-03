#include<iostream>
#include<queue>
using namespace std;
typedef int ElementType;
void HeapInsert(ElementType*& arr, int Position);
void Heapifly(ElementType* array, int index, int Size);
class MaxHeap
{
public:
	MaxHeap();
	~MaxHeap();
	void Create(int MaxSize);  // 建堆 
	void Create(int* arr,int num);
	bool IsFull();    // 判断堆是否满
	bool Insert(ElementType item);   // 插入元素
	bool IsEmpty();    //  判断堆是否为空
	friend void Swap(ElementType* array, int p1, int p2);
	ElementType DeleteMax();  // 删除并返回堆中最大元素
	void LevelOrderTraversal();  // 层序遍历 
	ElementType* getelmentArray();

private:
	friend void Heapifly(ElementType* array,int Position,int Size);
	void DeepCopy();
	friend void HeapInsert(ElementType* &array,int Position);
	ElementType* elmentArray;
	int Size;
	int Capicity;
};

MaxHeap::MaxHeap()
{
	this->Capicity = 16;
	this->Size = 0;
	this->elmentArray = new ElementType[16];
}

MaxHeap::~MaxHeap()
{
	this->Capicity = 0;
	this->Size = 0;
	delete this->elmentArray;
}

void MaxHeap::Create(int MaxSize)
{
	if (MaxSize > this->Capicity)
	{
		this->Capicity = MaxSize;
		this->elmentArray = new ElementType[Capicity];
	}
	for (int index = 0; index < MaxSize; ++index)
	{
		cin >> this->elmentArray[index];
		this->Size++;
		HeapInsert(this->elmentArray, index);
	}
}

void MaxHeap::Create(int* Array,int num)
{
	if (num > this->Capicity)
	{
		this->Capicity = num;
		this->elmentArray = new ElementType[Capicity];
	}
	for (int index = 0; index < num; ++index)
	{
		elmentArray[index] = Array[index];
		this->Size++;
		HeapInsert(this->elmentArray, index);
	}
}

bool MaxHeap::IsFull()
{
	if (this->Size+1 >= this->Capicity)
	{
		return true;
	}
	return false;
}

void Swap(ElementType* array, int p1, int p2)
{
	if (array == NULL)
	{
		return;
	}
	else
	{
		ElementType Temp = array[p2];
		array[p2] = array[p1];
		array[p1] = Temp;
	}
}


void HeapInsert(ElementType*& arr, int Position)
{
	int Parent = (Position - 1) / 2;
	while (arr[Position] > arr[Parent])
	{
		Swap(arr, Parent, Position);
		Position = Parent;
		Parent = (Position - 1) / 2;
	}
	//跳出循环时，说明当前的Position已经小于他的父元素 或 其已经到树根顶头 ：ElementArray[0]=ElementArray[0]
}

bool MaxHeap::Insert(ElementType item)
{

	if (this->IsFull())
	{
		cout << "Heap is Full" << endl;
		this->DeepCopy();
		this->Insert(item);
	}
	else
	{
			this->elmentArray[Size++] = item;
			HeapInsert(this->elmentArray, this->Size);
			return true;
	}
	return false;
}

bool MaxHeap::IsEmpty()
{
	if (this->Size == 0)
	{
		return true;
	}
	return false;
}

ElementType MaxHeap::DeleteMax()
{
	ElementType root = this->elmentArray[0];
	for (int index = 1; index < this->Size; ++index)
	{
		elmentArray[index - 1] = elmentArray[index];
	}
	this->Size--;
	for (int index = 0; index < this->Size; ++index)
	{
		Heapifly(this->elmentArray, index, this->Size);
	}
	return root;
}

void MaxHeap::LevelOrderTraversal()
{
	if (this->elmentArray == NULL)
	{
		return;
	}
	for (int index = 0; index < this->Size; ++index)
	{
		cout << elmentArray[index] << " ";
	}
	cout << endl;
}

ElementType* MaxHeap::getelmentArray()
{
	if (this->elmentArray == NULL)
	{
		return nullptr;
	}
	return this->elmentArray;
}



void Heapifly(ElementType* array,int index,int Size)
{
	if (array == NULL)
	{
		return;
	}
	int Left = index * 2+1;
	while (Left<Size)
	{
		int Largest = array[Left + 1] > array[Left] && Left + 1 <Size ? Left + 1 : Left;
		Largest = array[index] > array[Largest] ? index : Largest;
		if (Largest == index)
		{
			break;
		}
		Swap(array,index, Largest);
		index = Largest;
		Left = index * 2+1;
	}
}

void MaxHeap::DeepCopy()
{
	const int temp = this->Capicity * 2;
	ElementType* _NewPoint = new ElementType[temp];
	for (int index = 0; index < this->Capicity; ++index)
	{
		_NewPoint[index] = this->elmentArray[index];
		delete &elmentArray[index];
	}
	this->elmentArray = _NewPoint;
}



void HeapSort(ElementType*& arr,int Size)
{
	int HeapSize = Size;
	if (arr == NULL||HeapSize<2)
	{
		return;
	}
	for (int index = 0; index < HeapSize; ++index)
	{
		HeapInsert(arr, index);
	}
	Swap(arr, 0, --HeapSize);
	while(HeapSize > 0)
	{
		Heapifly(arr, 0, HeapSize);
		Swap(arr, 0, --HeapSize);
	}
}

ElementType* ReturnTemp_Array(ElementType* Array, int Size)
{
	ElementType* Data = new int[Size];
	for (int index = 0; index < Size; ++index)
	{
		Data[index] = Array[index];
	}
	return Data;
}
