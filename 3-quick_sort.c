#include "sort.h"

/**
 * swap1 - swap elements of an array
 * @arr: array data set
 * @size: size of array
 * @p1: first element
 * @p2: second element
 */

void swap1(int arr[], int size, int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	print_array(arr, size);
}

/**
 * partition - returns swapped array elemets
 * @arr: array data set
 * @size: size of array
 * @low: lowest value
 * @high: highest value
 * Return: value
 */

int partition(int arr[], int size, int low, int high)
{
	int pivot = arr[high], i = (low - 1), j;
	(void) size;

	for (j = low; j <= high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap1(arr, size, &arr[i], &arr[j]);
		}
	}
	swap1(arr, size, &arr[i + 1], &arr[high]);
	return (i);

}

/**
 * sort - sort array
 * @size: size of array
 * @low: lowest value
 * @high: highest value
 */

void sort(int arr[], int size, int low, int high)
{
	int pi;
	(void) size;

	if (low < high)
	{
		pi = partition(arr, size, low, high);

		sort(arr, size, low, pi - 1);
		sort(arr, size, pi + 1, high);
	}
}

/**
 * quick_sort - sort array
 * @array: array data set
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	size_t i;
	int arr[200];

	for (i = 0; i < size; i++)
		arr[i] = array[i];
	sort(arr, size, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
	for (i = 0; i < size; i++)
		array[i] = arr[i];
}

