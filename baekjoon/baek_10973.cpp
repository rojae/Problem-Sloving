#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SIZE;

int main(){
    cin >> SIZE;
    vector<int> v(SIZE);

    for(int i=0; i<SIZE; i++)
        cin >> v[i];
    
    if(!prev_permutation(v.begin(), v.end())){
        cout << -1;
    }
    else{
        //for(auto& i : v)
        for(int i=0; i<v.size(); i++)
            cout << v.at(i) << ' ';
        return 0;
    }
}