#include "Stack.h"

MyStack::MyStack(size_t size)
	{
		arr = new int[size + 1]();
		arr[0] = dno;
		top = 0;
		maxelv = size;
	}
MyStack::~MyStack()
{
	delete[] arr;
}


bool MyStack::isEmpty()
{
	
		return top == 0;
}

bool MyStack::isFull()
{
	
	return top == (int)maxelv;
}

void MyStack::push(int x)
{
	if (!isFull())
	{
		arr[++top] = x;
	}
	else { std::cout << "Stack full" << std::endl; }
}

int MyStack::pop()
{
	if (!isEmpty())
	{
		int res = arr[top];
		arr[top--] = 0;
		return res;
		}
	else { std::cout << "Stack is empty" << std::endl; }
	return dno;
}

int MyStack::GetOccupancy()
{
	return top;
}

size_t MyStack::GetCapacity()
{
	return maxelv;
}
