#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) {
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

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		vector<int> a(n + 1, -1);
		vector<int> b(n + 1, -1);
		vector<bool> v(201, false);
		vector<bool> av(201, false);
		
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			a[i] = tmp;
		}
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			b[i] = tmp;
		}
		vector<int> dp(n+1, 0);
		dp[1] = a[1];
		av[1] = true;
		v[b[1]] = true;
		for (int i = 2; i <= n; i++) {
			if (av[i - 1]) {
				//³¯Â¥ ¾È °ãÄ§
				if (!v[b[i]]) {
					dp[i] = max(dp[i - 1] + a[i], a[i]);
					v[b[i]] = true;
					av[i] = true;

				}
				//³¯Â¥ °ãÄ§
				else {
					int befor;
					for (int j = 1; j < i; j++) {
						if (b[j] == b[i]) {
							befor = j;
						}

					}

					if (a[befor] <= a[i]) {
						dp[i] = max(dp[i - 1] + a[i] - a[befor], a[i]);
						av[i] = true;
					}
					else {
						dp[i] = dp[i - 1];

					}
				}
			}
			else {
				int tmp_t;
				for (int j = 1; j < i; j++) {
					if(!av[j]) {}
				}
				dp[i] = max(dp[i - 1], a[i - 1] + a[i]);
				if (dp[i] == a[i-1]+a[i]) {
					av[i] = true;
					av[i - 1] = true;
				}
				else {
					continue;
				}
				
			}
			

			
		}
		int result;
		result = *max_element(dp.begin(), dp.end());
		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}