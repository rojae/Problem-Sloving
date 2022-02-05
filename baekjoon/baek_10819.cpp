#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int SIZE;
int arr[8];
int ans=0;

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
    cin >> SIZE;

    for(int i=0; i<SIZE; i++)
        cin >> arr[i];

    sort(arr, arr+SIZE);

    do{
        int sum = 0;

        for(int i=0; i<SIZE-1; i++){
            sum += abs(arr[i] -  arr[i+1]);
        }

        ans = (sum > ans)? sum : ans;

    }while(next_permutation(arr, SIZE));
    
    cout << ans;
    
    return 0;
}