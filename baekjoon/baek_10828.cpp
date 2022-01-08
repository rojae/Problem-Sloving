#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    int n;
    string cmd;
    stack<int> st;

    cin >> n;

    while(n > 0){
        cin >> cmd;

        if(cmd=="push"){
            int num;
            cin >> num;
            st.push(num);
        }
        else if (cmd=="top"){
            if(st.empty())
                cout << -1 << endl;
            else
                cout << st.top() << endl;
        }
        else if (cmd=="size"){
            cout << st.size() << endl;
        }
        else if (cmd=="empty"){
            if(st.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (cmd=="pop"){
            if(st.empty()){
                cout << -1 << endl;
            }
            else{
                cout << st.top() << endl;
                st.pop();
            }
        }
        n--;
    }    
}
