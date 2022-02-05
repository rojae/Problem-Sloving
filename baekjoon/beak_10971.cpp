#include <iostream>

using namespace std;

bool visit[11];
int arr[11][11];
int ans = (int)1e10;
int SIZE;

void dfs(int start, int y, int sum, int cnt){
    if(cnt == SIZE && y == start){
        if(sum < ans)
            ans = sum;
        return;
    }
    for(int x=0; x<SIZE; x++){
        if(arr[y][x] == 0)
            continue;
        if(!visit[y] && arr[y][x] > 0){
            visit[y] = true;
            sum += arr[y][x];

            if(ans >= sum)
                dfs(start, x, sum, cnt+1);

            visit[y] = false;
            sum -= arr[y][x];
        }
    }
}

int main(){
    cin >> SIZE;

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0,0,0,0);

    cout << ans;

    return 0;

}