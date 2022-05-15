#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int ans = 0;

    // citations을 오름차순으로 정렬하자.
    sort(citations.begin(), citations.end());

    // 0~n까지 루프 문
    // (hIndex = n-i)
    // citations[i]가 hIndex 이상이라면, answer에 hIndex를 저장. 반복 중지
    for(int i=0; i<citations.size(); i++){
        int hIndex = citations.size() - i;

        if(hIndex <= citations[i]){
            ans = hIndex;
            break;
        }
    }

    return ans;
}

int main(){
    vector<int> c = {3, 0, 6, 1, 5};
    cout << solution(c);
    return 0;
}
