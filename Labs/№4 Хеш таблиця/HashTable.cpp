#include <iostream>
#include<string>
using namespace std;
struct Node
{
	int key;
	string value;
	Node() : key(-1), value("") {}
};

class HashTable
{
private:
	static const int DEL_SYMBOL = -2;
	static const int MAGIC_SYMBOL = -1;
	size_t occupancy;
	size_t MAX_SIZE = 20;
	Node* MyTable;
public:
	HashTable() {
		MyTable = new Node[MAX_SIZE];
		for (size_t i = 0; i < MAX_SIZE; ++i)
		{
			MyTable[i].key = MAGIC_SYMBOL;
		}
		occupancy = 0;
	}
	~HashTable() { delete[] MyTable; }
	void rozshyr()
	{
		if (isFull())
		{
			size_t old_size = MAX_SIZE;
			MAX_SIZE *= 2;
			Node* new_table = new Node[MAX_SIZE];
			for (size_t i = 0; i < MAX_SIZE; ++i) 
			{
			 
				new_table[i].key = MAGIC_SYMBOL;
			}
			for (size_t i = 0; i < old_size; ++i)
			{
			if (MyTable[i].key != MAGIC_SYMBOL) {
				int new_hash = Hash(MyTable[i].key); 
				while (new_table[new_hash].key != MAGIC_SYMBOL) {
					new_hash = (new_hash + 1) % MAX_SIZE;
				}
				new_table[new_hash] = MyTable[i];
			}
		}
		cout << "Expanded" << endl;
		delete[] MyTable;
		MyTable = new_table;
	}
	}

	bool isFull()

	{
		bool isTrue;
		if (occupancy == MAX_SIZE) 
		{
			isTrue = true;
			cout << "Table is full! You need to use 'rozshyr' " << endl;
		}
		else
		{
			isTrue = false;
		}
		return isTrue;
		

	}
	int Hash(int key) {
		const int SpecialNUM = 31; 
		return (key * SpecialNUM) % MAX_SIZE;
	}
	void insert(int key, const string& value)
	{
		if (isFull()) { rozshyr(); }
		size_t index = Hash(key);
		while (MyTable[index].key != MAGIC_SYMBOL && MyTable[index].key != DEL_SYMBOL)
		{
			if (MyTable[index].key == key)
			{
				MyTable[index].value = value;
				return;
			}
		index = (index + 1) % MAX_SIZE;
		}
	
	MyTable[index].key = key; MyTable[index].value = value;
	occupancy++; 
}
	void clear()
	{
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			MyTable[i].key = MAGIC_SYMBOL;
			MyTable[i].value = "";
		}
		occupancy = 0;
	}
	Node find(int key)
	{
		int key_to_find = Hash(key);
		int start = key_to_find;
		while (MyTable[key_to_find].key != MAGIC_SYMBOL)
		{
			if (MyTable[key_to_find].key == key)
			{
				return MyTable[key_to_find];
			}
			key_to_find = (key_to_find + 1) % MAX_SIZE;
			if (key_to_find == start) {	break; }
		}
		return Node();
	}
	size_t Rozmir()
	{
		return occupancy;
	}
	void delet(int key)
	{
		int index = Hash(key);
		int start = index;
		while (MyTable[index].key != MAGIC_SYMBOL) {
			if (MyTable[index].key == key) {
				MyTable[index].key = DEL_SYMBOL;
				MyTable[index].value = "";
				occupancy--; 
				cout << "deleted." << endl;
				return;
			}
				if (index == start) break;
			index = (index + 1) % MAX_SIZE;
		}

	
		cout << "not found." << endl;
	}

	void print() {
		cout << "Hash Table:" << endl;
		for (size_t i = 0; i < MAX_SIZE; ++i) {
			if (MyTable[i].key != MAGIC_SYMBOL && MyTable[i].key != DEL_SYMBOL) {
				cout << "Index " << i << ": Key = " << MyTable[i].key
					<< ", Value = " << MyTable[i].value << endl;
			}
		}
	}

};