#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
    string str;     // 입력 숫자
    int m, ans=0, s;  // m 진수, ans 정답, s 입력의 길이

    cin >> str >> m;

    s = str.size();

    for(int i=0; i<s; i++){
        int n;

        if(str[i] >= '0' && str[i] <= '9')
            n = (str[i] - '0');
        else 
            n = (str[i] - 'A') + 10;
        
        ans += (pow(m,(s-(i+1))) * n);
    }

    cout << ans;

}