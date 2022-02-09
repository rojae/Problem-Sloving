#include <iostream>
#include <bitset>
#include <string>

// add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
// remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
// check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
// toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
// all: S를 {1, 2, ..., 20} 으로 바꾼다.
// empty: S를 공집합으로 바꾼다. 

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int data = 0;

    int t;
    cin >> t;

    while(t--){
        string cmd;
        cin >> cmd;

        switch (cmd[1]){
            int n;

            case 'd':
                cin >> n;
                data |= (1 << n);
                break;
            case 'e':
                cin >> n;
                data &= ~(1 << n);
                break;
            case 'h': {
                cin >> n;
                bool a = data & (1 << n);
                if(a)
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
                break;
            }
            case 'o':
                cin >> n;
                data ^= (1 << n);
                break;
            case 'l':
                data = ~(0);
                break;
            case 'm':
                data = 0;
                break;
        }
    }
    return 0;
}