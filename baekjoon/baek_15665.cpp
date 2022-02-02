#include <iostream>
#include <vector>
#include <algorithm>


#define MAX 8

using namespace std;

int n, m;
int arr[MAX] = {0,};
vector<int> v;

void dfs(int prevIdx, int prevValue, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else{
        int xx = 0;
        for(int i=0; i<n; i++){
            if(v.at(i) != xx){
                arr[cnt] = v.at(i);
                xx = v.at(i);
                dfs(i, v.at(i), cnt+1);
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

    dfs(-1, -1, 0);

    return 0;
}