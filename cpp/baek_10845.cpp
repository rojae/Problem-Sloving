#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int cnt;

    cin >> cnt;

    while(cnt--){
        string cmd;
        cin >> cmd;

        if(cmd == "push"){
            int n;
            cin >> n;
            v.push_back(n);
        }
        else if(cmd == "pop"){
            // 맨 앞의 원소를 출력하고 제거한다
            if(!v.empty()){
                cout << v.front() << endl;
                v.erase(v.begin());
            }
            else
                cout << -1 << endl;
        }
        else if(cmd == "size"){
            cout << v.size() << endl;
        }
        else if(cmd == "empty"){
            if(!v.empty())
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else if(cmd == "front"){
            if(v.empty())
                cout << -1 << endl;
            else
                cout << v.front() << endl;
        }
        else if(cmd == "back"){
            if(v.empty())
                cout << -1 << endl;
            else
                cout << v.back() << endl;
        }

    }

}
