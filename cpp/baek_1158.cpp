#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> q;

    for(int i=1; i<n+1; i++)
        q.push(i);
    
    cout << "<";

    // 항상 출력 대상, 검사의 대상은 queue의 front이다.
    while(!q.empty()){
        for(int i=0; i<m; i++){
            // 원형 구조를 유지시키기 위해서, 다시 push
            if(i != m-1)
                q.push(q.front());
            // 원형 구조 유지가 아닌 경우
            // 마지막 원소 출력의 경우
            else if(q.size() == 1)
                cout << q.front();
            // 원형 구조 유지가 아닌 경우
            // 무조건 출력 대상이다.
            else
                cout << q.front() << ", ";

            // 원형 구조 유지가 아닌 경우 -> pop()
            // 원형 구조 유지를 위해서, front 다시 push -> front를 pop()
            q.pop();
        }
    }

    cout << ">";
}