#include <iostream>
#include <algorithm>

using namespace std;
int D[100001][3], A[100001][2];
int main() {
	int n, T;
	int ans = 0;
	cin >> T;
	for (int k = 0; k < T; k++){
		cin >> n;
		for (int i = 0; i < 2; i++){
			for (int j = 1; j <= n; j++){
				cin >> A[j][i];
			}
		}
		D[0][0] = D[1][0] = D[2][0] = 0;
		for (int i = 1; i <= n; i++){
			D[i][0] = max(D[i - 1][2], max(D[i - 1][0], D[i - 1][1]));
			D[i][1] = max(D[i - 1][0], D[i - 1][2]) + A[i][0];
			D[i][2] = max(D[i - 1][0], D[i - 1][1]) + A[i][1];
		}

		for (int i = 1; i <= n; i++){
			ans = max(max(D[i][1], D[i][2]), max(ans, D[i][0]));
		}
		cout << ans << '\n';
		ans = 0;
	}
}
