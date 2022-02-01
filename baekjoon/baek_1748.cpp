#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    long ans=0;

    cin >> n;

    int len = log10(n) + 1;

    for(int i=0; i<len; i++){
        // 1~9 = 0
        // ans += (10^0 * 9) * (1) 1 = 자릿수 
        ans += ( pow(10, i) * 9 ) * (i+1);
    }

    ans += (n - pow(10,len) + 1) * len;

    cout << ans;
    return 0;
}