#include <iostream>

using namespace std;

int main(){
    int n, A, B;
    long long ans = 0;
    cin >> n;

    int *a = new int[n];

    for(int i=0; i<n; i++)
        cin >> a[i];

    cin >> A >> B;

    for(int i=0; i<n; i++)
        a[i] = a[i] - A;

    ans += n;

    for(int i=0; i<n; i++){
        
        if(a[i] > 0){
            ans += a[i] / B;
            if(a[i] % B > 0)
                ans += 1;
        }

    }

    cout << ans;
    return 0;
    

}