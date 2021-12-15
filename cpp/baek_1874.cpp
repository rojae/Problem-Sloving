#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    stack<int> st;          // 수열을 관리하는 스택
    string res = "";        // 결과 문자열
    int current = 1;        // 수열을 만들기 위해서 사용하는 1~n까지의 수 (시작 1)
    int n;                  // 입력되는 수열 갯수
    cin >> n;

    // 최악 100,000^2 < 1s
    for(int i=1; i<=n; i++){
        int target;         // 수열을 만들기 위해서 입력된 숫자
        cin >> target;
        
        for(; current<=n+1; current++){             // 수열의 숫자는 증가를 하며, 마지막은 n+1이다 (마지막 pop처리)
            if(st.empty() || st.top() != target){   // 수열을 만들 수 없는 경우 PUSH
                st.push(current);
                res += "+\n";
            }
            else if(st.top() == target){            // 수열을 만들 수 있는 경우
                st.pop();
                res += "-\n";
                break;                              // current를 재사용할 수 있음 (다시 반복문)
            }
        }
    }

    if(!st.empty()){
        cout << "NO" << endl;
    }else{
        cout << res << endl;
    }

}
