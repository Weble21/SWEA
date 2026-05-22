#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//1-2+3-4+5-6
		int n;
		cin >> n;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 2 != 0) {
				res += i;
			} else {
				res -= i;
			}
		}
		cout << "#" << t << " " << res << endl;
	}

}
