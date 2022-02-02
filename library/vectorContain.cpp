#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

bool isContain(int e){
    if(std::find(v.begin(), v.end(), e) != v.end())
        return true;
    return false;
}

int main(){
    for(int i=1; i<10; i++)
        v.push_back(i);

    cout << "0 is contains? : " << isContain(0) << '\n';
    cout << "1 is contains? : " << isContain(1) << '\n';

    return 0;
}