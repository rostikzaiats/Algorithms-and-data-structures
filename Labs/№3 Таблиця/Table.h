#pragma once
#include<iostream>
#include <string>


using namespace std;

struct  TableNode
{
	size_t key;
	string value;
	TableNode* next = nullptr;

};

class Table
{
private:
	TableNode* Head;
	size_t count;
public:
	Table() { Head = nullptr; count = 0; }
	~Table() {
		while (Head != nullptr)
		{
			TableNode* victim = Head;
			Head = Head->next;
			delete victim;
		};
	}
	void put(size_t k, const string& val);
	string find(size_t k);
	bool contain(size_t k);
	size_t Size();
	void print();
	void del(size_t k);
	size_t* getAllKeys();
	string* getAllData();

};
