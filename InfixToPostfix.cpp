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
		//����ÿ���ַ���˵��Ҫ�ж�һ��
		//���������    ������ַ�    if-else
		//������ַ��ָ÷�������ۣ��������ȼ���  ���������Ų�����  ���������Ų�����   һ���ַ���ջ��
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
