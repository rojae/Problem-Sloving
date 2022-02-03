/*
* ==================================================
* FileName : nextPermutation.cpp
* author : rojae
* description 
* 다음 수열 구하는 함수
* ==================================================
*/

#include<iostream>

using namespace std;

bool next_permutation(int *a, int n){
	int i = n-1;					// 뒤부터 시작 
	while(i > 0 && a[i] <= a[i-1])	// 어디까지가 감소수열인가?? 
		i -= 1;
	if(i <= 0)						// 전체가 감소수열이다. 
		return false;				// 다음 수열은 존재하지 않는다.
	int j = n-1;
	while(a[i-1] >= a[j])			// i-1보다 작거나 같은 뒤에 있는 수 찾기  
		j -= 1;			
	swap(a[i-1],a[j]);				// 찾은 수의 바로 앞 swap i-1 
	j = n - 1;						// j는 마지막 
	while(i < j){					// i-1 이후로, swap해줌 
		swap(a[i],a[j]);
		i +=1;
		j -=1;
	}
	return true;
}

int main(){
    int n = 9;
	
	int *v = new int[n];

	for(int i = 0; i < n; i++)
		v[i] = i+1;
		
	do{
		for(int i = 0; i < n; i++)
			cout << v[i] << ' ';
		cout << '\n';
	}while(next_permutation(v,n));
	
	return 0;
}