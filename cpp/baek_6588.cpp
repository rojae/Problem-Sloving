#include <iostream>

#define MAX 1000000

using namespace std;

bool* sieveOfEratos(){
    bool* arr = new bool[MAX+1];

    arr[0] = true;
    arr[1] = true;

    for(int i=2; i*i<=MAX; i++){
        if(arr[i] == false){
            for(int j=i*i; j<=MAX; j+=i){
                arr[j] = true;
            }
        }
    }   
    return arr;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = -1;

    bool* arr = sieveOfEratos();

    while(n != 0){
        cin >> n;

        for(int i=2; i<n-1; i++){
            if((!arr[i]) && (!arr[n-i]) && (i % 2 != 0) && ((n-1) % 2 != 0)){
                cout << n << " = " << i << " + " << n-i << '\n';
                break;
            }
        }
    }

    delete arr;

    return 0;
}