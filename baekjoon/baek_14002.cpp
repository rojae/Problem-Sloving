#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, ans=0, ansIdx=0;
    cin >> n;

    int *a = new int[n+1];
    vector<int> *dp = new vector<int>[n+1];

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[i] > a[j] && dp[i].size() <= dp[j].size()){
                
                // 반례 예외처리
                // dp[i]의 2차원 배열의 내용을 탐색하여, 보다 큰 값이 있으면 제거.
                for(int m=0; m<dp[i].size(); m++){
                    if(dp[i][m] >= a[j])
                        dp[i].erase(dp[i].begin() + m);
                }

                dp[i].push_back(a[j]);
            }
        }

        for(int m=0; m<dp[i].size(); m++){
            cout << "dp[" << i << "][" << m << "] : " << dp[i][m] << endl;
        }
        
    }

    // 정답을 가지고 있는 배열을 찾는다.
    // ans : 부분수열 길이
    // ansIdx : 부분수열의 마지막 인덱스
    for(int i=1; i<=n; i++){
        if(ans <= dp[i].size()){
            ans = dp[i].size();
            ansIdx = i;
            cout << ansIdx << endl;
        }
    }


    // 결과 출력
    if(n == 1 || ans == 0){
        cout << 1 << '\n';
        cout << a[1];   
    }
    else{
        cout << ans + 1 << '\n';

        dp[ansIdx].push_back(a[ansIdx]);
        sort(dp[ansIdx].begin(), dp[ansIdx].end());

        for(int i=0; i<dp[ansIdx].size(); i++){
            if(i == dp[ansIdx].size()-1)
                cout << dp[ansIdx].at(i);
            else
                cout << dp[ansIdx].at(i) << ' ';
        }
    }

    return 0;
}