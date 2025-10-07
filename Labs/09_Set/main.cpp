#include<iostream>
using namespace std;
class BitSet
{
private:
	unsigned int data;

	void BadIndex(char letter) const { if (letter < 'a' || letter > 'z') { throw("Out of range!"); } }
public:
	BitSet() :data(0) {}
	void add(char letter)
	{
		BadIndex(letter);
		int index = letter - 'a';
		unsigned int bit_place = 1 << index;
		data |= bit_place;
	}
	void remove(char letter)
	{
		BadIndex(letter); int index = letter - 'a';
		unsigned int bit_place = ~(1 << index);
		data &= bit_place;
	}
	bool contain(char letter) const
	{
	 BadIndex(letter); 
		int index = letter - 'a';
		unsigned int bit_place = 1 << index;
		return (data & bit_place) != 0;
	}
	bool isEmpty() const { return data == 0; }
	BitSet& operator=(const BitSet& other)
	{
		if (this->data != other.data)
		{
			data = other.data;
			
		}
		return *this;
	}
	BitSet unionWith(const BitSet& other)
	{
		BitSet result;
		result.data = this->data | other.data;
		return result;
	}
	BitSet IntersectionOf(const BitSet& other)
	{
		BitSet result;
		result.data = this->data & other.data;
		return result;
	}
	BitSet DistinctionWith(const BitSet& other)
	{
		BitSet result;
		result.data = this->data & ~other.data;
		return result;
	}
	void print() const
	{
		if (isEmpty()) {
			cout << "Set is empty!" << endl;
			return;
		}
			for (char letter = 'a'; letter <= 'z'; ++letter)
			{
				if (contain(letter)) cout << letter << " ";
			}
			cout << std::endl;
		
	}
};
//int main()
//{
//	BitSet set1;
//	BitSet set2;
//
//	
//	set1.add('a');
//	set1.add('b');
//	set1.add('c');
//
//	set2.add('b');
//	set2.add('d');
//
//	cout << "Set 1: ";
//	set1.print();
//
//	cout << "Set 2: ";
//	set2.print();
//
//	cout << "Set 1 contains 'a': " << (set1.contain('a') ? "Yes" : "No") << endl;
//	cout << "Set 2 contains 'a': " << (set2.contain('a') ? "Yes" : "No") << endl;
//
//	
//	BitSet unionSet = set1.unionWith(set2);
//	cout << "Union of Set 1 and Set 2: ";
//	unionSet.print();
//
//	BitSet intersectionSet = set1.IntersectionOf(set2);
//	cout << "Intersection of Set 1 and Set 2: ";
//	intersectionSet.print();
//
//	
//	set1.remove('b');
//	cout << "Set 1 after removing 'b': ";
//	set1.print();
//
//	return 0;
//}