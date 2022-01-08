#include <iostream>

using namespace std;

int d[201][201];

int main(void)
{
    int n, k;
    cin >> n >> k;
    d[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l <= j; ++l) {
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= 1000000000;
            }
        }
    }
    cout << d[k][n];
    return 0;
}
