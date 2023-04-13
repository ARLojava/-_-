#include<iostream>
using namespace std;
struct OcNode
{
	OcNode* Right;
	OcNode* Down;

	int Value;     //可以更换为其他类型的的Value值
	int Row;       //也可以通过Union值进行三个值的赋值
	int Col;       //注意其内存大小数据
	               //理解Union类的使用后回来编写
};
class OcNodeList
{
public:
	void RowDisplay();
	void ColDisplay();
	void Delete_LineList(OcNode* head);
	OcNodeList();
	OcNodeList(int* Matrix,int Row,int Col);//传入一个二维数组
	~OcNodeList();

private:
	OcNode* RowHead;
	OcNode* ColHead;
	int Row;
	int Col;
};


void OcNodeList::RowDisplay()
{
    OcNode* RPtrl = this->RowHead;
    while (RPtrl->Down != NULL)
    {
        OcNode* Ptrl = RPtrl;
        while (Ptrl->Right != NULL)
        {
            cout << Ptrl->Value << endl;
            Ptrl = Ptrl->Right;
        }
        RPtrl = RPtrl->Down;
    }
}

OcNodeList::OcNodeList()
{
	this->RowHead = NULL;
	this->ColHead = NULL;
	this->Row = 0;
	this->Col = 0;
}

OcNodeList::OcNodeList(int* Matrix, int Row, int Col)
{
    OcNode** RowHeads = new OcNode * [Row];
    OcNode** ColHeads = new OcNode * [Col];
    this->Row = Row;
    this->Col = Col;
    for (int i = 0; i < Row; ++i)
    {
        RowHeads[i] = NULL;
    }

    for (int j = 0; j < Col; ++j)
    {
        ColHeads[j] = NULL;
    }
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Col; ++j)
        {
            if (Matrix[i * Row + j] != 0)
            {
                OcNode* temp = new OcNode;
                temp->Right = NULL;
                temp->Down = NULL;
                temp->Row = i;
                temp->Col = j;

                if (RowHeads[i] != NULL)
                {
                    OcNode* RPtrl = RowHeads[i];
                    while (RPtrl->Right != NULL)
                    {
                        RPtrl = RPtrl->Right;
                    }
                    RPtrl->Right = temp;
                }
                else
                {
                    RowHeads[i] = temp;
                }
                if (ColHeads[j] != NULL)
                {
                    OcNode* CPtrl = ColHeads[j];
                    while (CPtrl->Down != NULL)
                    {
                        CPtrl = CPtrl->Down;
                    }
                    CPtrl->Down = temp;
                }
                else
                {
                    ColHeads[j] = temp;
                }
            }
        }
    }
    OcNode* tempRowHead = NULL;
    for (int i = 0; i < Row; ++i)
    {
        if (RowHeads[i] != NULL)
        {
            if (tempRowHead == NULL)
            {
                tempRowHead = RowHeads[i];
            }
            else
            {
                OcNode* Ptrl = tempRowHead;
                while (Ptrl->Down != NULL)
                {
                    Ptrl = Ptrl->Down;
                }
                Ptrl->Down = RowHeads[i];
            }
        }
    }
    this->RowHead = tempRowHead;
    OcNode* tempColHead = NULL;
    for (int i = 0; i < Row; ++i)
    {
        if (ColHeads[i] != NULL)
        {
            if (tempColHead == NULL)
            {
                tempColHead = ColHeads[i];
            }
            else
            {
                OcNode* Ptrl = tempColHead;
                while (Ptrl->Right != NULL)
                {
                    Ptrl = Ptrl->Right;
                }
                Ptrl->Right= ColHeads[i];
            }
        }
    }
    this->ColHead = tempColHead;
}

OcNodeList::~OcNodeList()
{
	
}