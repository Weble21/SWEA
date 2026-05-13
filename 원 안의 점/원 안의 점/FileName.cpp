#include <iostream>
#include <cmath>

using namespace std;

int pow(int a) {
	return a * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (pow(i) + pow(j) <= pow(n)) {
					cnt++;
				}
			}
		}
		cnt = ((cnt * 4) -(4*n)) - 3;

		cout << "#" << t << " " << cnt << endl;
	}
}