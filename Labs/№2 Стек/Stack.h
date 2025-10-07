#pragma once
#include<iostream>

class MyStack
{
private:
	int* arr;
	int top;
	const int dno = -1;
	size_t maxelv;
public:
	MyStack(size_t size);
	~MyStack();
	bool isEmpty();
	bool isFull();
	void push(int x);
	int pop();
	int GetOccupancy();
	size_t GetCapacity();
    int peek()
	{
		if (!isEmpty())
		{
			int res = arr[top];
			return res;
		}
		else { std::cout << "Stack is empty" << std::endl; }
		return dno;
	}
};