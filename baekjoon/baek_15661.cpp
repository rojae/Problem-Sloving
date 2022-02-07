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

// 14889번 문제의 변형문제이다.
// 스타트팀과 링크팀의 인원이 다를 수 있기 때문에
// 39번 라인의 반복문을 추가하여, 순열을 계산한다.
// 이때 11100, 00111의 경우는 같기 때문에
// end 조건을 잘 걸어주자.
int main(){
    cin >> n;

    bool *team = new bool[n];
    int arr[20][20];


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int mix = 1;
    int end = n/2 + n%2 + 1;

    while(mix != end){
        for(int i=0; i<mix; i++)
            team[i] = true;
        for(int i=mix+1; i<n; i++)
            team[i] = false;

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
        mix++;
    }
    cout << ans;
    return 0;
}