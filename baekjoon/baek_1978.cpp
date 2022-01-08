#include <iostream>

using namespace std;

#define MAX 1000

// 소수이면 false
// 소수가 아니면 true이다
bool* sieveOfEratos(){
    bool *arr = new bool[MAX+1];

    arr[0] = true;
    arr[1] = true;

    for(int i=2; i*i <= MAX+1; i++){
        if(arr[i] == false){
            for(int j=i*i; j<=MAX+1; j+=i){
                arr[j] = true;
            }
        }
    }

    return arr;
}

int main(){
    int ans = 0;
    int t;
    cin >> t;
    
    bool *arr = sieveOfEratos();

    while(t--){
        int n;
        cin >> n;
        if(!arr[n])
            ans++;
    }

    cout << ans;
}