#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<vector<int>> v(2, vector<int>(n, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		if (n == 1) {
			cout << max(v[0][0], v[1][0]) << endl;
			continue;
		}
		vector<vector<int>> dp(2, vector<int>(n, 0));
		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		dp[0][1] = v[0][1] + dp[1][0];
		dp[1][1] = v[1][1] + dp[0][0];
		for (int i = 2; i < n; i++) {
			dp[0][i] = v[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = v[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
		int res;
		res = max(dp[0][n - 1], dp[1][n - 1]);
		cout << res << endl;
	}
}