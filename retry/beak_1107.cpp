#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool btn[10];

bool isPossible(int n){
    string s = to_string(n);

    for(int i=0; i<s.size(); i++){
        if(!btn[s[i] - '0'])
            return false;
    }
    return true;
}

int main(){
    int n, now=100;
    int t;

    cin >> n >> t;

    for(int i=0; i<10; i++){
        btn[i] = true;
    }

    for(int i=0; i<t; i++){
        int idx;
        cin >> idx;
        btn[idx] = false;
    }
   // 100번부터 순수하게 +, -로만 이동한 경우
    int ans = 100 - n;
    if(ans < 0)
        ans = abs(ans);
    int comp = 0;

    while(true){
        if(isPossible(n+comp)){
            int count = 0;
            string s = to_string(n+comp);
            count += s.size();
            count += comp;
            ans = min(ans, count);
        }
        if(isPossible(n-comp)){
            int count = 0;
            string s = to_string(n-comp);
            count += s.size();
            count += comp;
            ans = min(ans, count);
        }
        if(100+n-comp < 0){
            break;
        }
        comp++;
    }

    cout << ans;
    return 0;
}