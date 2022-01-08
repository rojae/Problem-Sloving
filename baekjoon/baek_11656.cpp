#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> v;
    string str;
    cin >> str;

    int s = str.size();
    
    for(int i=0; i<s; i++){
        v.push_back(str.substr(i, s));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
        cout << v[i] << '\n';
}
