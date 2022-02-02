#include <iostream>
#include <vector>
#include <algorithm>


#define MAX 8

using namespace std;

int n, m;
bool visit[MAX];
int arr[MAX] = {0,};
vector<int> v;
std::vector<std::vector<int> > ans;

void dfs(int cnt){
    if(cnt == m){
        vector<int> tmp;

        for(int i=0; i<m; i++)
            tmp.push_back(arr[i]);

        ans.push_back(tmp);

        return;
    }
    else{
        int xx = 0;
        for(int i=0; i<n; i++){
            if(!visit[i] && v.at(i) != xx){
                visit[i] = true;
                arr[cnt] = v.at(i);
                xx = arr[cnt];
                dfs(cnt+1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    dfs(0);

    for(int i=0; i<ans.size(); i++){
        vector<int> el = ans.at(i);
        
        for(int j=0; j<el.size(); j++)
            cout << el.at(j) << ' ';
        cout << '\n';
    }

    return 0;
}