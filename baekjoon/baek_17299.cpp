#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    stack<int> st;

    cin >> n;

    int *arr = new int[n+1]();      // 입력배열
    int *ans = new int[n+1]();      // 정답배열
    int *ngf = new int[1000001]();  // 등장횟수를 저장하는 배열
    
    for(int i=1; i<=n; i++){
        int n;
        cin >> n;
        arr[i] = n;     // 입력배열
        ngf[n] += 1;    // 등장횟수 +1
    }

    // 우측에서부터 
    for(int i=n; i>=1; i--){
        // 현재 숫자의 등장횟수 >= 스택 top의 등장횟수
        // 스택 top의 숫자는 이제 필요없음 (pop)
        // 이 연산을 반복한다.
        while(!st.empty() && ngf[st.top()] <= ngf[arr[i]]){
            st.pop();
        }
        // 가장 우측의 정답배열은 -1이다.
        if(st.empty() || i==n){
            ans[i] = -1;
        }
        // 현재 숫자의 등장횟수 < 스택 top의 등장횟수
        // 정답배열에 넣어준다.
        else if(ngf[st.top()] > ngf[arr[i]]){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';

}
