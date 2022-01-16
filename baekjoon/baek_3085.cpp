#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int mkAns(int ans, vector< vector<char> > v){

    // 행 검사
    for(int i=0; i<v.size(); i++){
        int count = 1;
        char ch = v[i][0];

        for(int j=1; j<v.size(); j++){
            if(v[i][j] == ch)
                count++;
            else
                count=1;

            ch = v[i][j];

            if(ans < count)
                ans = count;
        }
    }

    // 열 검사
    for(int i=0; i<v.size(); i++){
        int count = 1;
        char ch = v[0][i];

        for(int j=1; j<v.size(); j++){
            if(v[j][i] == ch)
                count++;
            else
                count=1;

            ch = v[j][i];

            if(ans < count)
                ans = count;
        }

    }

    return ans;
}

int main(){
    int n, ans=0;
    cin >> n;

    vector< vector<char> > v;
    
    for(int i=0; i<n; i++){
        vector<char> vv;
        for(int j=0; j<n; j++){
            char input;
            cin >> input;
            vv.push_back(input);
        }
        v.push_back(vv);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i-1 >= 0){
                vector< vector<char> > tempV;
                tempV = v;          

                char a = tempV[i][j];
                tempV[i][j] = tempV[i-1][j];
                tempV[i-1][j] = a;
                ans = mkAns(ans, tempV);
            }
            if(i+1 < n){
                vector< vector<char> > tempV;
                tempV = v;          

                char a = tempV[i][j];
                tempV[i][j] = tempV[i+1][j];
                tempV[i+1][j] = a;
                ans = mkAns(ans, tempV);
            }
            if(j-1 >= 0){
                vector< vector<char> > tempV;
                tempV = v;          

                char a = tempV[i][j];
                tempV[i][j] = tempV[i][j-1];
                tempV[i][j-1] = a;
                ans = mkAns(ans, tempV);
            }
            if(j+1 < n){
                vector< vector<char> > tempV;
                tempV = v;          

                char a = tempV[i][j];
                tempV[i][j] = tempV[i][j+1];
                tempV[i][j+1] = a;
                ans = mkAns(ans, tempV);
            }
        }
    }

    cout << ans;
    return 0;
}