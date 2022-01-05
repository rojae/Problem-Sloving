#include<iostream>
#include<algorithm>
using namespace std;

int a[100001];
int d[100001][2];       // d[i][0] : 삭제하지 않았을 경우, d[i][1] : 삭제한 경우

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = a[0];
    for (int i = 0; i < n; i++) {
        d[i][0] = d[i][1] = a[i];
        if (i == 0) 
            continue;
        d[i][0] = max(d[i - 1][0] + a[i], a[i]);
        d[i][1] = max(d[i - 1][0], d[i - 1][1] + a[i]);
        ans = max(ans,max(d[i][0], d[i][1]));
    }
    cout << ans << '\n';
    return 0;
}