#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		vector<int> v;
		if (n == 0) {
			break;
		}
		
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		for (int i = 1; i < n; i++) {
			int tmp;
			cin >> tmp;
			int cmp = v[i-1] + tmp;
			if (cmp > tmp) {
				v.push_back(cmp);
			}
			else {
				v.push_back(tmp);
			}
		}
		int res;
		res = *max_element(v.begin(), v.end());
		cout << res << "\n";
	}

	return 0;
}