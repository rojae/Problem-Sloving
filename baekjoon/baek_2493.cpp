#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int *arr = new int[n];
    stack<int> st;

    cin >> arr[0];
    st.push(0);
    ans.push_back(0);

    for(int i=1; i<n; i++){
        cin >> arr[i];

        while(!st.empty()){
            if(arr[st.top()] >= arr[i]){
                ans.push_back(st.top() + 1);
                break;
            }
            st.pop();
        }
        if(st.empty()){
            ans.push_back(0);
        }
        st.push(i);
    }

    for(int i=0; i<ans.size(); i++)
        cout << ans.at(i) << ' ';

    return 0;
}


// 아래는 시간 초과 발생한 코드
// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// int n;
// vector<int> ans;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n;

//     int *arr = new int[n];

//     for(int i=0; i<n; i++)
//         cin >> arr[i];

//     for(int i=n-1; i>0; i--){
//         stack<int> st;
//         int target = arr[i];

//         for(int j=0; j<i; j++){
//             st.push(arr[j]);
//         }
//         while(!st.empty()){
//             int top = st.top();
//             if(target <= top){
//                 ans.push_back(st.size());
//                 break;
//             }
//             else
//                 st.pop();
//         }
//     }

//     for(int i=ans.size(); i<n; i++)
//         ans.push_back(0);

//     for(int i=ans.size()-1; i>=0; i--)
//         cout << ans.at(i) << ' ';

//     return 0;
// }