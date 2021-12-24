#include <iostream>

using namespace std;

int gcd(int x, int y);

int main(){
    int n, s = 0;
    cin >> n;

    while(n--){
        cin >> s;

        int *arr = new int[s];

        long long ans = 0;

        for(int i=0; i<s; i++)
            cin >> arr[i];

        for(int i=0; i<s-1; i++){
            for(int j=i+1; j<s; j++){
                ans += gcd(arr[i], arr[j]);
            }
        }

        cout << ans << endl;
        delete[] arr;
    }
    
    return 0;
}

int gcd(int x, int y){
    if(y==0)    return x;
    else return gcd(y, x%y);
}