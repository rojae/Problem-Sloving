#include<iostream>
#include<string>

using namespace std;

int main()
{
	int A,B,C,result;
	int arr[10] = {0};
	cin >> A >> B >> C;
	result = A*B*C;
	
	// 1�� �ڸ��� ���´�.
	// result�� 10�� ���� 
	while(result != 0)
	{
		arr[result % 10] += 1;
		result /= 10;
	}
	for(int i =0; i <10; i++)
	{
		cout<< arr[i] << endl;
	}
	return 0;
}
