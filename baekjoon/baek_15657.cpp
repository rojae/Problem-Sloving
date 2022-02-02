#include <iostream>
#include <vector>
#include <algorithm>


#define MAX 8

using namespace std;

int n, m;
int arr[MAX] = {0,};
vector<int> v;

void dfs(int prev, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else{
        for(int i=0; i<n; i++){
            if(prev <= v.at(i)){
                arr[cnt] = v.at(i);
                dfs(v.at(i), cnt+1);
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

    dfs(0, 0);

    return 0;
}