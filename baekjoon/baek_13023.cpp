#include <iostream>
#include <vector>

using namespace std;

#define MAX 2000+1
int n,m;                // n : 사람수, m : 친구 관계 수
vector<int> v[MAX];     // 그래프 친구 관계
bool visit[MAX];
bool ans;

void dfs(int depth, int cnt){
    if(cnt == 4){
        ans = true;
        return;
    }
    else{
        visit[depth] = true;
        for(int i=0; i<v[depth].size(); i++){
            int next = v[depth][i];
            if(visit[next] == false)
                dfs(next, cnt+1);
            if(ans)
                return;
        }
        visit[depth] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        dfs(i,0);
        if(ans)
            break;
    }
    
    cout << ans;

    return 0;
}