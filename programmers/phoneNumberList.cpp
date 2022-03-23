#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
bool solution(vector<string> phone_book);

int main(){
    vector<string> v = {"11","12","111"};
    if(solution(v))
        cout << "true";
    else
        cout << "false";
    return 0;
}

bool solution(vector<string> phone_book) {
    vector<string> v;

    for(auto i : phone_book)
        v.push_back(i);

    sort(v.begin(), v.end());

    for(int i=0; i<v.size()-1; i++){
        if(v.at(i) == v.at(i+1).substr(0, v.at(i).size()))
            return false;
    }

    return true;
}