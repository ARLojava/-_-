#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
typedef string Element_type;
struct TreeNode
{
	Element_type Value;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode();
};
TreeNode::TreeNode()
{
	Value = '0';
	this->Left = nullptr;
	this->Right = nullptr;
}
class BinTree
{
public:
	void preorderTravel();          //递归的前序遍历
	void InorderTravel();           //递归的中序遍历
	void PostorderTravel();         //递归的后序遍历
	void Levelorder();              //一般的层次遍历
	bool Isempty();
	void CreateTree_base();                      //基本创建树的方法
	void CreateTree_pre_with_Inorder(string pre,string inorder);          //特别创建树的方法
	void CreateTree_Post_with_Inorder(string Inorder_Str,string Post_Str);         //特别创建树的方法
	TreeNode* get_root();
	BinTree();                                   //初始化
	~BinTree();                                  //析构

private:
	TreeNode* root;
	void auxiliary_function_pre(TreeNode* Node);      //辅助函数：辅助于前序遍历
	void auxiliary_function_Inorder(TreeNode* Node);  //辅助函数：辅助于中序遍历
	void auxiliary_function_Post(TreeNode* Node);     //辅助函数：辅助于后序遍历
	TreeNode* auxiliary_function_SP1(string pre, string Inorder, int& cur);
	TreeNode* auxiliary_function_SP2(string Inorder, string Post, int& cur);
	int Find(string Str, char target);
	int Length;
};
TreeNode* CreateBinTree(char*& ch)
{

	TreeNode* Node = nullptr;
	if (*ch == '#')
	{
		return Node;
	}
	else
	{
		Node = new TreeNode;
		Node->Value = *ch;
		Node->Left = CreateBinTree(++ch);
		Node->Right = CreateBinTree(++ch);
	}
	return Node;
}
void BinTree::CreateTree_base()
{
	string item;
	cin >> item;
	char* charArray = (char*)item.c_str();
	this->root = CreateBinTree(charArray);
}
void BinTree::CreateTree_pre_with_Inorder(string preStr,string InStr)
{
	int current = 0;
	this->root=this->auxiliary_function_SP1(preStr, InStr,current);
}
void BinTree::CreateTree_Post_with_Inorder(string in,string Po)
{
	int current = Po.size() - 1;
	this->root=this->auxiliary_function_SP2(in, Po, current);
}
TreeNode* BinTree::get_root()
{
	return this->root;
}
BinTree::BinTree()
{
	this->root = nullptr;
	this->Length = 1;
}
BinTree::~BinTree()
{

}
void BinTree::auxiliary_function_pre(TreeNode* Node)
{
	if (Node == NULL)
	{
		return;
	}
	else
	{
		cout << Node->Value << " ";
		auxiliary_function_pre(Node->Left);
		auxiliary_function_pre(Node->Right);
	}
	return;
}
void BinTree::auxiliary_function_Inorder(TreeNode* Node)
{
	if (Node != NULL)
	{
		auxiliary_function_Inorder(Node->Left);
		cout << Node->Value <<" ";
		auxiliary_function_Inorder(Node->Right);
	}
}
void BinTree::auxiliary_function_Post(TreeNode* Node)
{
	if (Node != NULL)
	{
		auxiliary_function_Post(Node->Left);
		auxiliary_function_Post(Node->Right);
		cout << Node->Value << " ";
	}
}

TreeNode* BinTree::auxiliary_function_SP1(string pre, string Inorder, int& cur)
{
	TreeNode* root = new TreeNode;
	if (Inorder =="\0")
	{
		return nullptr;
	}
	root->Value = pre[cur];
	int spite = this->Find(Inorder, pre[cur]);
	string Left, right;
	Left = Inorder.substr(0,spite);
	right = Inorder.substr(spite + 1, Inorder.size() - 1);
	cur++;
	root->Left = auxiliary_function_SP1(pre, Left, cur);
	root->Right = auxiliary_function_SP1(pre, right, cur);
	return root;
}

TreeNode* BinTree::auxiliary_function_SP2(string Inorder, string Post, int& cur)
{
	if (Inorder == "\0")
	{
		return nullptr;
	}
	TreeNode* root = new TreeNode();
	root->Value = Post[cur];
	int spite = this->Find(Inorder, Post[cur]);
	string left, right;
	left = Inorder.substr(0, spite);
	right = Inorder.substr(spite + 1, Inorder.size() - 1);
	cur--;
	root->Right = auxiliary_function_SP2(right, Post, cur);
	root->Left = auxiliary_function_SP2(left, Post, cur);
	return root;
}

int BinTree::Find(string Str, char target)
{
	for (int i = 0; i <= Str.size(); ++i)
	{
		if (Str[i] == target)
		{
			return i;
		}
	}
	return -1;
}

int Tree_Length(BinTree Tree)
{
	return 0;
}
void preorderTravel(BinTree* Tree)
{
	//非递归的前序遍历
	stack<TreeNode*>* s = new stack<TreeNode*>();
	TreeNode* current = Tree->get_root();
	s->push(current);
	while (!(s->empty()))
	{
		current = s->top();
		s->pop();
		cout << current->Value << " ";
		if (current->Right != NULL)
		{
			s->push(current->Right);
		}
		if (current->Left != NULL)
		{
			s->push(current->Left);
		}
	}
}
void InorderTravel(BinTree* Tree)
{
	//非递归的中序遍历
	stack<TreeNode*>* s = new stack<TreeNode*>();
	TreeNode* current = Tree->get_root();
	s->push(current);
	while (current&&!(s->empty()))
	{
		while (current!=NULL&&current->Left!=NULL)
		{
			s->push(current->Left);
			current = current->Left;
		}
		if (!(s->empty()))
		{
			current = s->top();
			s->pop();
			cout << current->Value << " ";
			if (current->Right != NULL)
			{
				s->push(current->Right);
				current = current->Right;
			}
		}
	}
}
void PostorderTravel(BinTree* Tree)
{
	//非递归的后序遍历
	stack<TreeNode*>* s = new stack<TreeNode*>();
	stack<TreeNode*>* ans = new stack<TreeNode*>();
	TreeNode* current = Tree->get_root();
	s->push(current);
	while (!(s->empty()))
	{
		current = s->top();
		s->pop();
		ans->push(current);
		if (current->Left != NULL)
		{
			s->push(current->Left);
		}
		if (current->Right != NULL)
		{
			s->push(current->Right);
		}
	}
	TreeNode* node = nullptr;
	while (!(ans->empty()))
	{
		node = ans->top();
		ans->pop();
		cout << node->Value << " ";
	}
	delete s;
	delete ans;
}
void Level_order(BinTree* Tree)
{
	//一般的层次遍历
	queue<TreeNode*>* Q = new queue<TreeNode*>();
	TreeNode* current = Tree->get_root();
	Q->push(current);
	while (!(Q->empty()))
	{
		current = Q->front();
		cout << current->Value << " ";
		Q->pop();
		if (current->Left != NULL) Q->push(current->Left);
		if (current->Right != NULL)  Q->push(current->Right);
	}
}
void BinTree::preorderTravel()
{
	this->auxiliary_function_pre(root);
}

void BinTree::InorderTravel()
{
	this->auxiliary_function_Inorder(this->root);
}

void BinTree::PostorderTravel()
{
	auxiliary_function_Post(this->root);
}
void BinTree::Levelorder()
{
	queue<TreeNode*>* Q = new queue<TreeNode*>();
	TreeNode* current = this->root;
	Q->push(current);
	while (!(Q->empty()))
	{
		current = Q->front();
		cout << current->Value << " ";
		Q->pop();
		if (current->Left != NULL) Q->push(current->Left);
		if (current->Right != NULL)   Q->push(current->Right);
	}
}
bool BinTree::Isempty()
{
	return this->root == NULL;
}
int main()
{
	BinTree* bt1 = new BinTree;
	BinTree* bt2 = new BinTree;
	string Pre_Str = "ABDFECGHI";
	string Inorder_Str = "DBEFAGHCI";
	string Post_Str = "DEFBHGICA";
	bt1->CreateTree_pre_with_Inorder(Pre_Str, Inorder_Str);
	bt1->preorderTravel();
	bt2->CreateTree_Post_with_Inorder(Inorder_Str, Post_Str);
	cout << endl;
	bt2->preorderTravel();
}