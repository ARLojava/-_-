#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int Prioity(char op)
{
	if (op == '(')
	{
		return 0;
	}
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '/' || op == '*')
	{
		return 2;
	}
}
void InfiToPostfix(stack<char>Stack, string Value,vector<char> &ans)
{
	for (auto Char : Value)
	{
		//对于每个字符来说都要判断一次
		//如果是数字    如果是字符    if-else
		//如果是字符又该分情况讨论：定义优先级？  定义左括号操作？  定义右括号操作？   一般字符入栈？
		if (isdigit(Char))
		{
			ans.push_back(Char);
		}
		else
		{
			if (Stack.empty())
			{
				Stack.push(Char);
			}
			else
			{
				if (Char == '(')
				{
					Stack.push(Char);
				}
				else
				{
					if (Char == ')')
					{
						while (Stack.top() != '(')
						{
							char temp = Stack.top();
							ans.push_back(temp);
							Stack.pop();
						}
						Stack.pop();
					}
					else
					{
						int Char_Prioity = Prioity(Char);
						int Top_Prioity = Prioity(Stack.top());
						while(Char_Prioity<=Top_Prioity)
						{
							char temp = Stack.top();
							ans.push_back(temp);
							Stack.pop();
							if (Stack.empty())
							{
								break;
							}
							Top_Prioity = Prioity(Stack.top());
						}
						Stack.push(Char);
			         }
					
				}
			}
		}
	}
	while (!Stack.empty())
	{
		ans.push_back(Stack.top());
		Stack.pop();
	}
}
