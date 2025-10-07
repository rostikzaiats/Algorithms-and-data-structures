
#include "Table.h"
using namespace std;
string Table::find(size_t k)
{
	if (Head == nullptr)
	{
		cout << "Error. Table is empty!" << endl; return "none";
	}
	TableNode* current = Head;
	while (current != nullptr)
	{
		if (current->key == k)
		{
			return current->value;
		}
		current = current->next;
	}
	cout << "Error. Table have not value for this key!" << endl; return "none";

}

bool Table::contain(size_t k)
{
	if (Head == nullptr)
	{
		cout << "Error. Table is empty!" << endl; return false;
	}
	bool is_true = false;
	TableNode* current = Head;
	while (current != nullptr)
	{
		if (current->key == k)
		{

			is_true = true;
		}
		current = current->next;
	}
	return is_true;
}

size_t Table::Size()
{
	return count;
}

void Table::put(size_t k, const string& val)
{
	if (Head == nullptr)
	{
		Head = new TableNode{ k, val, nullptr };
		count++;  return;
	}
	TableNode* current = Head;
	TableNode* prev = nullptr;
	while (current != nullptr)
	{
		if (current->key == k)
		{
			current->value = val; return;
		}
		prev = current;
		current = current->next;
	}
	TableNode* newNode = new TableNode;
	prev->next = newNode;
	newNode->key = k;
	newNode->value = val;
	newNode->next = nullptr;
	count++;
}
void Table::print()
{
	if (Head == nullptr)
	{
		cout << "Error. Table is empty!" << endl; return;
	}
	TableNode* current = Head;
	while (current != nullptr)
	{
		cout << "|" << current->key << "|" << current->value << "|" << endl;
		current = current->next;

	}

}
void Table::del(size_t k)
{
	if (Head == nullptr)
	{
		cout << "Error. Table is empty!" << endl; return;
	}
	TableNode* current = Head;
	TableNode* victim = nullptr;
	if (Head->key == k) {
		victim = Head;
		Head = Head->next;
		delete victim;
		count--;
		return;
	}
	while (current->next != nullptr && current->next->key != k) { // Шукаємо від попереднього -> наступний щоб там поточний не став нуллптр
		// бо буде неможливо видалити останній
		current = current->next;
	}
	if (current->next == nullptr) {
		cout << "Error. Table have not value for this key!" << endl; return;
	}
	victim = current->next;
	current->next = victim->next;
	delete victim;
	count--;
}
size_t* Table::getAllKeys()
{
	if (count == 0) {
		cout << "Error. Table is empty!" << endl;
		return nullptr;
	}
	size_t* keys = new size_t[count];
	TableNode* current = Head;
	for (size_t i = 0; i < count; ++i)
	{
		keys[i] = current->key;
		current = current->next;
	}
	return keys;


}
string* Table::getAllData()
{
	if (count == 0) { return nullptr; }
	string* Data = new string[count];
	TableNode* current = Head;
	for (size_t i = 0; i < count; ++i)
	{
		Data[i] = current->value;
		current = current->next;
	}
	return Data;

}