#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> startTeam;
vector<int> linkTeam;

int startScore;
int linkScore;
long ans = 100000000;

bool desc(int a, int b){
    return a > b;
}

int main(){
    cin >> n;

    bool *team = new bool[n];
    int arr[20][20];

    for(int i=0; i<n/2; i++)
        team[i] = true;
    for(int i=n/2; i<n; i++)
        team[i] = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    // 순열을 통해서 문제를 해결하자
    // 1100 1001 ... 
    // 1100 -> startTeam[0,1], linkTeam[2,3]
    do{
        for(int i=0; i<n; i++){
            if(team[i])
                startTeam.push_back(i);
            else
                linkTeam.push_back(i);
        }
        
        for(int i=0; i<startTeam.size()-1; i++){
            for(int j=i+1; j<startTeam.size(); j++){
                startScore += arr[startTeam[i]][startTeam[j]] + arr[startTeam[j]][startTeam[i]];
            }
        }

        for(int i=0; i<linkTeam.size()-1; i++){
            for(int j=i+1; j<linkTeam.size(); j++){
                linkScore += arr[linkTeam[i]][linkTeam[j]] + arr[linkTeam[j]][linkTeam[i]];
            }
        }
        
        int scoreGap = abs(startScore - linkScore);

        ans = (ans > scoreGap)? scoreGap : ans;

        startTeam.clear();
        linkTeam.clear();
        startScore = 0;
        linkScore = 0;

    }while(next_permutation(team, team+n, desc));
    
    cout << ans;
    return 0;
}