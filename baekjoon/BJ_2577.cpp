#include<iostream>
#include<string>

using namespace std;

int main()
{
	int A,B,C,result;
	int arr[10] = {0};
	cin >> A >> B >> C;
	result = A*B*C;
	
	// 1의 자리만 얻어온다.
	// result는 10씩 감소 
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
