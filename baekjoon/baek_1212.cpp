#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 8진수 to 2진수
string eightToTwo(string str, int s){
    string ans = "";

    for(int i=0; i<s; i++){
        if(str[i] == '0')   {
            ans += "000";
        }
        else if(str[i] == '1'){
            ans += "001";
        }
        else if(str[i] == '2'){
            ans += "010";
        }
        else if(str[i] == '3'){
            ans += "011";
        }
        else if(str[i] == '4'){
            ans += "100";
        }
        else if(str[i] == '5'){
            ans += "101";
        }
        else if(str[i] == '6'){
            ans += "110";
        }
        else if(str[i] == '7'){
            ans += "111";
        }
    }
    
    // 앞자리 0지우기
    for(int i=0; i<ans.size(); i++){
        if(ans[0] == '0'){
            ans = ans.substr(1, ans.size());
        }
        else 
            break;
    }
    
    return ans;
}


int main(){
    string str;
    cin >> str;

    string ans = eightToTwo(str, str.size());

    cout << ans;

}