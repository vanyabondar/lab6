// lab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "cmath"
#include "iostream"

using namespace std;
struct tree
{
	tree* left;
	tree* right;
	tree* parent;
	int value;
	bool isNum;
};



tree* AddOperation(int num1, int num2, char oper, tree *&MyTree)
{
	tree *temp = new tree;
	tree *left = new tree;
	tree *right = new tree;
	temp->value = oper;
	left->value = num1;
	right->value = num2;
	temp->parent = MyTree;
	temp->left = left;
	temp->right = right;
	return temp;
}

int doOperation(tree *MyTree) {
	int x = 0;
	switch (MyTree->value)
	{

	case '^':
		x = pow(MyTree->left->value, MyTree->right->value);
		break;
	case '/':
		x = MyTree->left->value / MyTree->right->value;
		break;
	case '*':
		x = MyTree->left->value * MyTree->right->value;
		break;
	case '-':
		x = MyTree->left->value - MyTree->right->value;
		break;
	case '+':
		x = MyTree->left->value + MyTree->right->value;
		break;
	}
	return x;
}

unsigned opPreced(int ch)
{
	switch (ch)
	{
	case '^':
		return 3;
	case '*'://множення
	case '/'://ділення
		return 2;
	case '+'://додавання
	case '-'://віднімання
		return 1;
	}
	return 0;
}

bool isOperator(char i) {
	return (i == '+' || i == '-' || i == '/' || i == '*' || i == '^');
}



/*void forBracket(List* firstStack, List * secondStack, bool flag) {
if (firstStack->Head->x != ')')
if ((firstStack->Head->Next->x != ')') && (opPreced(firstStack->Head->x) < opPreced(firstStack->Head->Next->x)))
{
int x = Pop(secondStack);
int y = Pop(firstStack);
forBracket(firstStack, secondStack, false);
Add(x, secondStack);
Add(y, firstStack);
forBracket(firstStack, secondStack, true);
}
else
{
int x = 0, y = 0;

switch (firstStack->Head->x)
{

case '^':
y = Pop(secondStack);
x = pow(y, Pop(secondStack));
break;
case '/':
y = Pop(secondStack);
x = y / Pop(secondStack);
break;
case '*':
x = Pop(secondStack) * Pop(secondStack);
break;
case '-':
y = Pop(secondStack);
x = y - Pop(secondStack);
break;
case '+':
x = Pop(secondStack) + Pop(secondStack);
break;
}
Add(x, secondStack);
Pop(firstStack);
if (flag == true)
forBracket(firstStack, secondStack, true);
}
}

void FillStacks(string inp, List* operations, List * operands) {
for (int i = inp.length() - 1; i >= 0; i--) {
if (inp[i] == '-' && (i == 0 || inp[i - 1] == '(')) {
Add(0, operands);
Add(inp[i], operations);
}
else if (inp[i] == ' ') {
continue;
}
else if (isOperator(inp[i]) || inp[i] == ')') {
Add(inp[i], operations);
}
else if (inp[i] == '(') {
forBracket(operations, operands, true);
Pop(operations);
}
else {
Add(inp[i] - '0', operands);
}
}
}*/

int main()
{
	tree * MyTree = nullptr;
	tree* Tree = AddOperation(2, 4, '^', MyTree);
	cout << doOperation(Tree);
	return 0;
}





