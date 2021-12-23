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

    int m, n;
    cin >> m >> n;

    bool *arr = sieveOfEratos();

    for(int i=m; i<=n; i++){
        if(!arr[i])
            cout << i << '\n';
    }

}