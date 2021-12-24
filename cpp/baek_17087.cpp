#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, s, ans = 1000000000;

    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        ans = min(ans, abs(s - a));
    }

    cout << ans;
}