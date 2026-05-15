#include <iostream>
#include <vector>

using namespace std;


int comp(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k;
		cin >> n >> k;
		
		int dp[101][1001] = { 0, };
		int v[101][2] = { 0, };

		for (int i = 1; i <= n; i++) {
			int vol, cash;
			cin >> vol >> cash;
			v[i][0] = vol;
			v[i][1] = cash;
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (j - v[i][0] >= 0) {
					dp[i][j] =
						comp(dp[i - 1][j], v[i][1] + dp[i - 1][j - v[i][0]]);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
				
			}
		}
		cout << "#" << t << " " << dp[n][k] << "\n";
	}
	return 0;
}