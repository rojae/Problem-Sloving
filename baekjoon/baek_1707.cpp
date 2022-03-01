#include <iostream>
#include <vector>

using namespace std;

bool ans;
int t,v,e;
vector<int> grape[20001];
int color[20001];

bool dfs(int node, int c){
    color[node] = c;
    
    for(int i = 0; i < grape[node].size(); i++){
        int next = grape[node][i];

        // 아직 탐색을 하지 않았고, dfs 탐색 결과 이분 그래프인 경우
    	if(color[next] == 0){
			if(dfs(next,3-c) == false)
				return false;
		}
        // 이분 그래프가 아님
		else if(color[next] == color[node])
				return false;
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--){
        ans = true;

        cin >> v >> e;

        for(int i=1; i<=v; i++){
            grape[i].clear();
            color[i] = 0;
        }

        // 그래프 입력
        for(int i=0; i<e; i++){
            int a,b;
            cin >> a >> b;
            grape[a].push_back(b);
            grape[b].push_back(a);
        }

        // 이분 상태 검사
        for(int i=1; i<=v; i++){
            if(color[i] == 0){
                if(dfs(i, 1) == false){
                    ans = false;
                }
            }
        }
        
        if(ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}