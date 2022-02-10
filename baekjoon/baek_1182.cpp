#include <iostream>

using namespace std;

int main(){
    // Speed up
    cin.tie(NULL);
	cout.tie(NULL);

    int n,s,ans=0;
    cin >> n >> s;

    int *a = new int[n];

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    // 2^n 부분수열 경우의 수 (공집합 제외)
    // 마지막 자릿수
    for(int i=1; i<(1 << n); i++){
        int sum = 0;

        // 1 ~ 마지막 전 자릿수
        for(int j=0; j<n; j++){
            if(i & (1 << j)){
                sum += a[j];
            }
        }

        ans = (sum == s)? ans + 1 : ans;
    }

    cout << ans;

    return 0;
}