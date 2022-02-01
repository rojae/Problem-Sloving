#include <iostream>
#define MAX 8

using namespace std;

int n,m;
int arr[MAX] = {0,};
bool visit[MAX] = {0,};

void dfs(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    else{
        for(int i=0; i<n; i++){
            if(!visit[i]){
                visit[i] = true;
                arr[cnt] = i+1;
                dfs(cnt+1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0);
    return 0;
}