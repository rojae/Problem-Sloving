#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n, max=0;
    stack<int> st;

    cin >> n;

    int *a = new int[n+1];
    int *dp = new int[n+1];

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }


    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<=i; j++){
            if(a[i] > a[j] && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
                if(dp[i] > max)
                    max = dp[i];
            }
        }
    }

    // n=1 수열 길이가 1인 경우 예외처리
    if(max == 0)
        max = 1;

    for(int i=n; i>=1; i--){
        if(max == 0)
            break;
        else if(max == dp[i]){
            st.push(a[i]);
            max--;
        }
    }

    cout << st.size() << '\n';
    
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}