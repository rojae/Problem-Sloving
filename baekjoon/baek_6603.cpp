#include <iostream>
#include <algorithm>

using namespace std;

int lotto[14];
int ans[6];
int n;

void dfs(int start, int depth){
    if(depth == 6){
        for(int i=0; i<6; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=start; i<n; i++){
        ans[depth] = lotto[i];
        dfs(i+1, depth+1);
    }
}
int main(){

    while(cin >> n && n!=0){
        for(int i=0; i<n; i++)
            cin >> lotto[i];
        dfs(0,0);
        cout << endl;
    }
 
    return 0;

}