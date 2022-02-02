#include <iostream>
#define MAX 8

using namespace std;

int n,m;
int arr[MAX] = {0,};

void dfs(int prev, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else{
        for(int i=0; i<n; i++){
            if(prev <= i+1){
                arr[cnt] = i+1;
                dfs(i+1, cnt+1);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0,0);
    return 0;
}

