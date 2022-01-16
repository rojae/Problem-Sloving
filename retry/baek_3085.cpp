#include <iostream>
#include <cmath>

using namespace std;

int n, ans=0;
char a[51][51];

int findAns();
void searchRow();
void searchCol();

// 정답 찾기
int findAns(){
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i-1 > 0){
                char tmp = a[i][j];
                a[i][j] = a[i-1][j];
                a[i-1][j] = tmp;
                searchRow();
                searchCol();
                a[i-1][j] = a[i][j];
                a[i][j] = tmp;
            }
            if(j-1>0){
                char tmp = a[i][j];
                a[i][j] = a[i][j-1];
                a[i][j-1] = tmp;
                searchRow();
                searchCol();
                a[i][j-1] = a[i][j];
                a[i][j] = tmp;
            }
            if(i+1<=n){
                char tmp = a[i][j];
                a[i][j] = a[i+1][j];
                a[i+1][j] = tmp;
                searchRow();
                searchCol();
                a[i+1][j] = a[i][j];
                a[i][j] = tmp;
            }
            if(j+1<=n){
                char tmp = a[i][j];
                a[i][j] = a[i][j+1];
                a[i][j+1] = tmp;
                searchRow();
                searchCol();
                a[i][j+1] = a[i][j];
                a[i][j] = tmp;
            }
        }
    }

    return ans;
}

// 열 검사
void searchRow(){
    for(int i=1; i<=n; i++){
        int count = 1;
        char ch = a[i][1];
        
        for(int j=2; j<=n; j++){
            if(ch == a[i][j])
                count++;
            else{
                ch = a[i][j];
                count = 1;
            }

            ans = max(ans, count);
        }
    }
}

// 행 검사
void searchCol(){
    for(int i=1; i<=n; i++){
        int count = 1;
        char ch = a[1][i];

        for(int j=2; j<=n; j++){
            if(ch == a[j][i])
                count++;
            else{
                ch = a[j][i];
                count = 1;
            }

            ans = max(ans, count);
        }
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    cout << findAns();
    return 0;
}