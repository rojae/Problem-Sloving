#include <iostream>
#include <string>

#define max 1000000

using namespace std;

bool* sieveOfEratos(){
    bool *arr = new bool[max+1];

    arr[0] = false;
    arr[1] = false;

    for(int i=2; i*i<=max; i++){
        if(arr[i] == false){
            for(int j=i*i; j<=max; j+=i){
                arr[j] = true;
            }
        }
    }

    return arr;
}

int main(){
    int t;
    cin >> t;

    bool *arr = sieveOfEratos();

    while(t--){
        int n, ans = 0;
        cin >> n;

        for(int i=2; i+i<=n; i++){
            if(arr[i] == false && arr[n-i] == false)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}