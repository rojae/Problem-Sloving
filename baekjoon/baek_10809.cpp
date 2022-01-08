#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;

    int s = str.size();
    int *ans = new int[26];

    for(int i=0; i<26; i++)
        ans[i] = -1;
    

    for(int i=0; i<s; i++){
        int ch = (int)str[i] - 'a';
        if(ans[ch] == -1)
            ans[ch] = i;
    }

    for(int i=0; i<26; i++)
        cout << ans[i] << ' ';

}