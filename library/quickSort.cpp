/*
* ==================================================
* FileName : quickSort.cpp
* Subject : quickSort algorithm 
* author : rojae
* 
* description 
* nlogn <= time <= n^2
* ==================================================
*/
#include <iostream>

using namespace std;

int arr[10] = { 23,123,324234,12312,2123,24,456,56,123,564 };

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort(int list[],int left,int right)
{
	if (left >= right)
		return;
	int pivot = left;
	int start = left + 1;
	int end = right;
	while (start<=end)
	{
		while (list[pivot] >= list[start] && start <= right)
			start++;
		while (list[pivot] <= list[end] && end > left)
			end--;
		if (start > end)
		{
			swap(list[pivot], list[end]);
		}
		else
			swap(list[start], list[end]);
	}
	quick_sort(list, left, end - 1);
	quick_sort(list, end + 1, right);

}

int main()
{
	quick_sort(arr,0,9);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}