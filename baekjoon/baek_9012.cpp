#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    int n;
    cin >> n;

    while(n--){
        stack<string> st;
        string str = "";
        cin >> str;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(')
                st.push("(");
            else{   // str[i] == ')'
                if(!st.empty() && st.top() == "("){
                    st.pop();
                }else{
                    st.push("X");       // 불능 (무조건 불가능)
                }
            }
        }

        if(st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

}