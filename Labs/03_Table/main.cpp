#include <iostream>
#include "Table.h"
int main()
{
	Table t1{};
	t1.put(25, "Banana");
	t1.put(1, "Makaka");
	t1.put(123, "Mops");
	cout << t1.contain(25) << endl;
	cout << t1.contain(1111) << endl;
	cout << t1.Size() << endl;

	t1.print();
	cout << "\n\n";
	t1.put(1, "Vilka");
	t1.put(23, "Lowka");
	t1.put(2, "Mykola");
	t1.print();
	t1.del(1);
	t1.del(123);
	t1.del(25);
	t1.del(2);
	cout << endl;
	t1.print();
	t1.del(23);
	t1.print();
	t1.put(1, "Vilka");
	t1.put(23, "Lowka");
	t1.put(2, "Mykola");
	for (size_t i = 0; i < t1.Size(); ++i)
	{
		cout << t1.getAllData()[i] << ' ';
		cout << t1.getAllKeys()[i] << endl;
	}
	system("pause");
}