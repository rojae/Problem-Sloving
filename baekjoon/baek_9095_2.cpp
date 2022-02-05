#include <iostream>

using namespace std;

int n;
int a;
int ans;

void dfs(int a, int sum){
    if(sum == a){
        ans++;
        return;
    }
    else if(sum > a)
        return;

    for(int i=1; i<=3; i++)
        dfs(a, sum+i);    
}

int main(){
    cin >> n;

    while(n--){
        cin >> a;
        ans=0;
        dfs(a, 0);
        cout << ans << '\n';
    }

    return 0;
}