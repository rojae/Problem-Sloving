#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    int *arr = new int[n]();
    stack<double> st;
    string str;

    cin >> str;

    // 변환 작업
    // ABC*+DE/- => 0123*+45/-
    for(int i=0; i<str.size(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            continue;
        else{
            str[i] = char ((str[i] - 'A') + '0');      // (str[i] - 'A') -> to char
        }
    }

    // 숫자 입력 저장
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // 연산작업
    for(int i=0; i<str.size(); i++){
        // 연산자일 경우, 스택에서 두개의 숫자를 뽑아서 연산처리
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            
            if(str[i] == '+')
                a = b + a;
            else if(str[i] == '-')
                a = b - a;
            else if(str[i] == '*')
                a = b * a;
            else
                a = b / a;

            st.push(a);
        }
        else{
            int idx = str[i] - '0';         // '0'을 0으로 변환
            st.push(arr[idx]);
        }
    }
    printf("%.2f\n", st.top());

}