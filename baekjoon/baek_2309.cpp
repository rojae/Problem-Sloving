#include <iostream>

using namespace std;

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

int main(){
    int total=0;
    bool done = false;

    int a[9];
    int ans[7];

    for(int i=0; i<9; i++){
        cin >> a[i];
        total += a[i];
    }

    for(int i=0; i<8; i++){
        if(done) break;
        for(int j=i+1; j<9; j++){
            if(done) break;
            if(total - a[i] - a[j] == 100){
                a[i] = -1;
                a[j] = -1;
                done = true;
            }
        }
    }

    quick_sort(a, 0, 8);

    for(int i=2; i<9; i++)
        cout << a[i] << ' ';

    return 0;
}