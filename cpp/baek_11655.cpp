#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;

    getline(cin, str);

    int s = str.size();
    
    for(int i=0; i<s; i++){
        int ch = str[i];

        if(ch >= 'a' && ch <= 'z'){
            ch += 13;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            str[i] = ch;
        }
        if(ch >= 'A' && ch <= 'Z'){
            ch += 13;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            str[i] = ch;
        }
    }

    cout << str;
}
