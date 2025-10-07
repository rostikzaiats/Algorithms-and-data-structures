#include <iostream>
#include <cstdlib>
void CountSort(int* arr, size_t n)
{
	int max = arr[0]; 	int min = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (max < arr[i]) { max = arr[i]; }
		if (min > arr[i]) { min = arr[i]; }

	}
	int diff = max - min + 1;
	int* help = new int[diff] {};
	for (int i = 0; i < n; ++i)
	{
		help[arr[i] - min]++;
	}
	size_t index = 0;
	for (int i = 0; i < diff; ++i)
	{
		while (help[i] > 0)
		{
			arr[index++] = i + min;
			help[i]--;
		}
	}

	delete[] help;



}
void main()
{
	size_t seed;
	std::cout << "Enter seed for randomizer: "; std::cin >> seed; std::cout << std::endl;
std:srand(seed);
	size_t size; 
	std::cout << "Enter array size: "; std::cin >> size; std::cout << std::endl;
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 11;
	}
	std::cout << "Your array: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "Sorted array: ";
	CountSort(array, size);
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;

	delete[] array;

}