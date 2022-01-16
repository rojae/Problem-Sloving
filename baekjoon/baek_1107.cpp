#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool broken[10];

bool possible(int n){
    string s = to_string(n);
    
    for(int i=0; i<s.size(); i++){
        int l = s[i] - '0';
        if(broken[l])
            return false; 
    }

    return true;
}

int main(){
    int target;
    int n, t;
    cin >> n >> t;

    for(int i=0; i<t; i++){
        int btn;
        cin >> btn;
        broken[btn] = true;
    }

    // 100번부터 순수하게 +, -로만 이동한 경우
    int ans = 100 - n;
    if(ans < 0)
        ans = abs(ans);
    int comp = 0;

    while(true){
        if(possible(n+comp)){
            int count = 0;
            string s = to_string(n+comp);
            count += s.size();
            count += comp;
            ans = min(ans, count);
        }
        if(possible(n-comp)){
            int count = 0;
            string s = to_string(n-comp);
            count += s.size();
            count += comp;
            ans = min(ans, count);
        }
        // 0
        // 1
        // 0 인 경우, 음수를 생각해야 함.
        if(100+n-comp == 0){
            break;
        }
        comp++;
    }

    cout << ans;
    return 0;


}