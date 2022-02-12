#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int a[20][20];
int n;
int ans=1e9;

vector<int> team1;
vector<int> team2;

int main(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<(1<<n); i++){
        team1.clear();
        team2.clear();

        for(int j=0; j<n; j++){
            if((i & (1<<j))== 0){
                team1.push_back(j);
            }
            else{
                team2.push_back(j);
            }
        }

        if(team1.size() > n/2 || team2.size() > n/2)
            continue;

        int team1Sum=0;
        int team2Sum=0;

        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                if(i==j)
                    continue;
                team1Sum += (a[team1[i]][team1[j]] + a[team1[j]][team1[i]]);
                team2Sum += (a[team2[i]][team2[j]] + a[team2[j]][team2[i]]);
            }
        }

        ans = (ans > abs(team1Sum - team2Sum))? abs(team1Sum - team2Sum) : ans;
    }

    cout << ans/2;
    return 0;
}