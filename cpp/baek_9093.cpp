#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    // getline과 cin을 함께 사용. 
    // cin은 개행문자 변수에 담지 않음 -> 입력버퍼에 남아서, 이후 getline에 영향을 준다.
    cin.ignore();       
    
    while(n--){
        stack<char> st;
        string str = "";
        getline(cin, str);
        str += ' ';

        for(int i=0; i<str.size(); i++){
            if(str[i] == ' '){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                cout << str[i];
            }
            else{
                st.push(str[i]);
            }
        }
    }

}