#include <iostream>

#define MAX 8

using namespace std;

bool visit[MAX];
int arr[MAX];
int n, m;

void dfs(int prev, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else{
        for(int i=0; i<n; i++){
            if(visit[i] == false && prev < i+1){
                visit[i] = true;
                arr[cnt] = i+1;
                dfs(i+1, cnt+1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0, 0);
    return 0;
}