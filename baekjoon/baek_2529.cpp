#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n;
int a[9];
string expr[9];
long maxAns;
long minAns=1e10;

int main(){
    cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    n = n+1;

    for(int i=0; i<n-1; i++)
        cin >> expr[i];

    // 최대 구하기
    for(int i=9, j=0; i>9-n; i--,j++){
        a[j] = i;
    }
    
    // 9876543210부터 시작
    do{
        bool check = true;

        for(int i=0; i<n-1; i++){
            if(expr[i] == "<")
                check = check && a[i] < a[i+1];
            else if(expr[i] == ">")
                check = check && a[i] > a[i+1];
        }

        if(check){
            long tmp = 0;
            for(int i=0; i<n; i++)
                tmp += pow(10, n-i-1) * (a[i]);
            
            maxAns = (maxAns < tmp)? tmp : maxAns;
            break;
        }

    }while(prev_permutation(a, a+n));

    // 최소 구하기
    for(int i=0; i<n; i++)
        a[i] = i;

    // 0123456789부터 시작
    do{
        bool check = true;

        for(int i=0; i<n-1; i++){
            if(expr[i] == "<")
                check = check && a[i] < a[i+1];
            else if(expr[i] == ">")
                check = check && a[i] > a[i+1];
        }

        if(check){
            long tmp = 0;
            for(int i=0; i<n; i++)
                tmp += pow(10, n-i-1) * (a[i]);

            minAns = (minAns > tmp)? tmp : minAns;
            break;
        }

    }while(next_permutation(a, a+n));

    // 숫자이기 때문에, 첫째 자리 '0'은 무시된다 (강제 출력)
    if( (int)log10(maxAns) + 1 < n)
        cout << '0';
    cout << maxAns << '\n';

    // (int)log10(minAns)=1 : minAns의 자릿수 구하기
    if( (int)log10(minAns) + 1 < n)
        cout << '0';
    cout << minAns << '\n';

    return 0;
}