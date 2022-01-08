#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<char> ans;
    int n, m;

    cin >> n >> m;

    while(n != 0){
        int mod = n % m;
        n = n/m;

        if(mod >= 10)    
            ans.push((mod - 10) + 'A');
        else 
            ans.push(mod + '0');
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
}