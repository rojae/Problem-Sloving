#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int ans = people.size();

    sort(people.begin(), people.end());

    int up = people.size() - 1;
    int down = 0;

    while(down < people.size()){
        if(up <= down)
            break;
        if(up > down && people.at(up) + people.at(down) <= limit){
            ans--;
            up--;
            down++;
        }
        else{
            up--;
        }
    }

    return ans;
}

int main(){
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;
    cout << solution(people, limit);
    return 0;
}