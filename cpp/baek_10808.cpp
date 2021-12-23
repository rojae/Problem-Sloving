#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;

    int s = str.size();
    int *ans = new int[26]();

    for(int i=0; i<s; i++){
        int ch = (int)str[i] - 'a';
        ans[ch]++;
    }

    for(int i=0; i<26; i++)
        cout << ans[i] << ' ';

}