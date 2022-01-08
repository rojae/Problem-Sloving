#include <iostream>
#include <string>

using namespace std;

void to(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            cout << i << '\n';
            return to(n/i);
        }
    }
    if(n>1)
        cout << n << '\n';
}

int main(){
    int n;
    cin >> n;

    to(n);
    return 0;
}