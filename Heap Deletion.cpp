#include<iostream>
using namespace std;

void heapinsert(int a[], int& size, int value)
{
	size = size + 1;
	a[size] = value;
	int i = size;

	while (i > 1)
	{
		int parent = i / 2;
		if (a[parent] < a[i])
		{
			swap(a[parent],a[i]);
			i = parent;
		}

		else
		{
			return;
		}
	}
}

void heapdelete(int a[], int& size)
{
	a[1] = a[size];
	size = size - 1;
	int i = 1;

	while (true)
	{
		int left = 2 * i;
		int right = 2 * i + 1;
		int largest = i;

		if (left <= size && a[left] > a[largest])
		{
			largest = left;
		}

		if (right <= size && a[right] > a[largest])
		{
			largest = right;
		}

		if (largest != i)
		{
			swap(a[i], a[largest]);
			i = largest;
		}
		else
		{
			return;
		}
	}
}

void main()
{
	const int maxsize = 6;
	int a[maxsize] = {};
	int size = 0;

	heapinsert(a, size, 1);
	heapinsert(a, size, 2);
	heapinsert(a, size, 3);
	heapinsert(a, size, 4);

	for (int i = 1; i <= size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	heapdelete(a, size);

	for (int i = 1; i <= size; i++)
	{
		cout << a[i] << " ";
	}
}
