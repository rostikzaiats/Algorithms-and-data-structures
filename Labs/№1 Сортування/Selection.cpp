#include <iostream>
#include <cstdlib>
void SelectSort(int* arr, size_t n)
{	
for(int i = 0; i < n-1; ++i){
	size_t minIndex = i;
	for (int j = i + 1; j < n; ++j)
	{
		if (arr[j] < arr[minIndex])
		{
			minIndex = j;
		}
	}
	std::swap(arr[i], arr[minIndex]);
}
}
void main()
{
	size_t seed;
	std::cout << "Enter seed for randomizer: "; std::cin >> seed; std::cout << std::endl;
	std::srand(seed);
	size_t size;
	std::cout << "Enter array size: "; std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i]=std::rand() % 10000;
	}
	std::cout << "Your array: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	SelectSort(arr, size);
	std::cout << "Sorted array: " << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	delete[] arr;
}