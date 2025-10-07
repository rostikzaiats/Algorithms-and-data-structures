
#include<iostream>
#include<Windows.h>
#include<queue>
using namespace std;
template<typename T>
struct  Node
{
	T value;
	int priority;
	Node *left, *right;
	Node() : value(T()), priority(0), left(nullptr), right(nullptr) {}
	Node(T val, int prior = 0) : value(val), priority(prior), left(nullptr), right(nullptr) {}
};
template<typename T>
class Queue
{
protected:
	Node<T> * head, * tail;
	size_t size;
public:
	Queue() : head(nullptr), tail(nullptr), size(0) {}
	Queue(size_t n, Node<T>* headNode = nullptr, Node<T>* tailNode = nullptr)
		: tail(tailNode), head(headNode), size(n) {
	}
	virtual ~Queue()
	{
		while (head != nullptr) { 
			Node<T>* temp = head;
			head = head->right;
			delete temp;  
		}
		tail = nullptr;  
		size = 0;
	}
	virtual bool isEmpty() const { return head == nullptr; }
	 void enqueue(T value)
	{
		if (isEmpty())
		{
			head = new Node<T>(value);
			tail = head;
		}
		else
		{
			tail->right = new Node<T>(value);
			tail = tail->right;
		}
		++size;

	}
	virtual T dequeue()
	{
		if (isEmpty()) { throw( "Queue is empty!"); }

		T value;
			if (head->right != nullptr)
			{
				Node<T>* current = head;
				head = head->right;
				head->left = nullptr;
				value = current->value;
				delete current;
				
				
			}
			else if (head == tail)
			{
				value = head->value;
				delete head;
				head = tail = nullptr;
			}
		size--;
		return value;
	}
	virtual T front() const
	{
		if (isEmpty()) { throw( "Queue is empty!"); }
		return head->value;
	}
	T back() const
	{
		if (tail == nullptr) { throw("Queue is empty!"); }
		return tail->value;

	}
	virtual void clear()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}
	virtual size_t sizeOf() const { return size; }

	virtual	void print() const {
		Node<T>* printNode = head;
		while (printNode != nullptr) {
			cout << printNode->value << endl;
			printNode = printNode->right;
		}
	}
};
template<typename T>
class priorityQueue : public Queue<T>
{
public:
	using Queue<T>::head;
	using Queue<T>::tail;
	using Queue<T>::size;

	void enqueue(T value, int priority) {
		Node<T>* newNode = new Node<T>(value, priority);

		if (head == nullptr) {
			head = tail = newNode;
		}
		else if (priority < head->priority) {
			newNode->right = head;
			head->left = newNode;
			head = newNode;
		}
		else {
			Node<T>* curr = head;

			
			while (curr->right != nullptr && curr->right->priority <= priority) {
				curr = curr->right;
			}

			
			newNode->right = curr->right;
			newNode->left = curr;
			curr->right = newNode;

			if (newNode->right != nullptr)
				newNode->right->left = newNode;
			else
				tail = newNode; 
		}
		++size;
	}
	virtual	void print() const override {
		Node<T>* printNode = head;
		while (printNode != nullptr) {
			cout << printNode->value << "/" << printNode->priority << 'p' << endl;
			printNode = printNode->right;
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\n=== Демонстрація роботи черг ===" << endl;

	cout << "\n=== Звичайна черга ===" << endl;
	Queue<int> q1;
	q1.enqueue(5);
	q1.enqueue(10);
	q1.enqueue(15);

	q1.print();
	cout << "Front: " << q1.front() << endl;
	cout << "Back: " << q1.back() << endl;
	cout << "Dequeued: " << q1.dequeue() << endl;
	cout << "Front після dequeue: " << q1.front() << endl;
	cout << "Size: " << q1.sizeOf() << endl;
	cout << "isEmpty: " << (q1.isEmpty() ? "Yes" : "No") << endl;
	q1.clear();
	cout << "Після clear, isEmpty: " << (q1.isEmpty() ? "Yes" : "No") << endl;

	cout << "\n=== Пріоритетна черга ===" << endl;
	priorityQueue<string> q2;
	q2.enqueue("Задача A", 3);
	q2.enqueue("Задача B", 1);
	q2.enqueue("Задача C", 2);
	q2.enqueue("Задача D", 1);

	q2.print();
	cout << "Front (найвищий пріоритет): " << q2.front() << endl;
	cout << "Back (найнижчий пріоритет): " << q2.back() << endl;
	cout << "Dequeued: " << q2.dequeue() << endl;
	cout << "Після dequeue:" << endl;
	q2.print();

	cout << "\n=== STL queue (стандартна черга) ===" << endl;
	queue<int> stlQueue;
	stlQueue.push(5);
	stlQueue.push(10);
	stlQueue.push(15);

	cout << "Елементи STL queue: ";
	while (!stlQueue.empty()) {
		cout << stlQueue.front() << " ";
		stlQueue.pop();
	}
	cout << endl;

	cout << "\n=== STL priority_queue (стандартна пріоритетна черга) ===" << endl;
	priority_queue<pair<int, string>> stlPriorityQueue;
	stlPriorityQueue.push({ 3, "Задача A" });
	stlPriorityQueue.push({ 1, "Задача B" });
	stlPriorityQueue.push({ 2, "Задача C" });
	stlPriorityQueue.push({ 1, "Задача D" });

	cout << "Елементи STL priority_queue (в порядку пріоритету):" << endl;
	while (!stlPriorityQueue.empty()) {
		auto top = stlPriorityQueue.top();
		cout << "Пріоритет " << top.first << ": " << top.second << endl;
		stlPriorityQueue.pop();
	}
	return 0;
}