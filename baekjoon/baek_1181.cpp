#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(string s1, string s2){
    if(s1.size() == s2.size())
        return s1 < s2;
    else
        return s1.size() < s2.size();
}

int main(){
    int n;
    vector<string> v;

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        if(find(v.begin(), v.end(), str) == v.end())
            v.push_back(str);
    }

    sort(v.begin(), v.end(), comp);
    for(int i=0; i<v.size(); i++)
        cout << v.at(i) << '\n';
    
    return 0;
}