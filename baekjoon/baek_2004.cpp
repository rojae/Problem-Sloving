#include <iostream>
#include <algorithm>

using namespace std;

int num(int a){
    int ans=0;
    while(a){
        ans+=a/5;
        a/=5;
    }
    return ans;
}
 
int num2(int a){
    int ans=0;
    while(a){
        ans+=a/2;
        a/=2;
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    cout << min(num(n)-num(n-m)-num(m),num2(n)-num2(n-m)-num2(m));
}