#include <iostream>

int binarySearch(int *array, int target, int min, int max)
{
	while (max >= min)
	{
		int middlePoint = min + (max - min) / 2;
		if (array[middlePoint] > target)
		{
			// Если array[midpoint] > target, то тогда понимаем, что искомое число не находится в правой половине массива.
			// Мы можем использовать midpoint - 1 в качестве индекса максимальной границы, так как в следующей итерации этот индекс вычислять не нужно
			max = middlePoint - 1;
		}
		else if (array[middlePoint] < target)
		{
			// Если array[midpoint] < target, то тогда понимаем, что искомое число не находится в левой половине массива.
			// Мы можем использовать midpoint + 1 в качестве индекса минимальной границы, так как в следующей итерации этот индекс вычислять не нужно
			min = middlePoint + 1;
		}
		else
			return middlePoint;
	}
}

int main()
{
	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	int index = binarySearch(array, x, 0, 14);

	if (array[index] == x)
		std::cout << "Good! Your value " << x << " is on position "<< index << " in array!\n";
	else
		std::cout << "Fail! Your value " << x << " isn't in array!\n";
	return 0;
}