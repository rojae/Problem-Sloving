#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int toDigit(int* arr, int a, int s){
    int sum = 0;

    for(int i=0; i < s; i++)
        sum += pow(a, s-(i+1)) * arr[i];

    return sum;
}

stack<int> toM(int sum, int b){
    stack<int> res;

    while(sum != 0){
        res.push(sum%b);
        sum = sum / b;
    }

    return res;
}

int main(){
    int a, b;
    int m;
    stack<int> ans;

    cin >> a >> b;
    cin >> m;
    int *arr = new int[m];

    for(int i=0; i<m; i++)
        cin >> arr[i];

    int sum = toDigit(arr, a, m);
    ans = toM(sum, b);

    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
    
}