#include <iostream>
#include <cmath>

#define SIZE 2

using namespace std;

int a[SIZE];        // 숫자 배열
int sz[SIZE];       // 숫자의 크기 배열 (10 = 2, 100 = 3)
int sum, add, substract;

// 숫자의 길이를 리턴
int digitSize(int n){
    return (int)log10(n) + 1;
}

int main(){
    // Speed up
    cin.tie(NULL);
	cout.tie(NULL);

    // 입력으로, 숫자, 숫자크기, 총합 계산
    for(int i=0; i<SIZE; i++){
        cin >> a[i];
        sum += a[i];
        sz[i] = digitSize(a[i]);
    }

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<sz[i]; j++){
            // 1240의 경우, one : 1,2,4,0  
            int one = int (a[i] / pow(10, j)) % 10;
            // 5의 경우, 최댓값 += 자릿수 + 1
            if(one == 5){
                add += 1 * pow(10, j);
            }
            // 6의 경우, 최솟값 -= 자릿수 - 1 
            else if(one == 6){
                substract += -1 * pow(10, j);
            }
        }
    }

    cout << sum + substract << ' ' << sum + add;
    return 0;
}