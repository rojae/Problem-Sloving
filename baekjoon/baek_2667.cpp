#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int graph[25][25];
bool visit[25][25] = {false, };
vector<int> ans;
int cntTmp;

void dfs(int x, int y){
    if(visit[x][y] == true || graph[x][y] == 0)
        return;
    else
        cntTmp++;
        visit[x][y] = true;

    for(int i=0; i<4; i++){
        if(dx[i] + x < 0 || dx[i] + x > s-1 || dy[i] + y < 0 || dy[i] + y > s-1
            || graph[dx[i]+x][dy[i]+y] == 0){
            continue;
        }
        else{
            dfs(dx[i]+x, dy[i]+y);
        }
    }
    return;
}

int main(){
    cin >> s;

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            if(visit[i][j] == false && graph[i][j] == 1){
                cntTmp = 0;
                dfs(i,j);
                ans.push_back(cntTmp);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans.at(i) << '\n';

    return 0;
}