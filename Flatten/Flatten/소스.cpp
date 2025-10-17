#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//25.10.17. 10:26 start
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int k = 0; k < 10; k++) {
		int t;
		cin >> t;

		vector<int> v(100);
		for (int i = 0; i < 100; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < t; i++) {
			auto it_max = max_element(v.begin(), v.end());
			auto it_min = min_element(v.begin(), v.end());
			int idx_max = distance(v.begin(), it_max);
			int idx_min = distance(v.begin(), it_min);
			v[idx_max] -= 1;
			v[idx_min] += 1;
		}
		int max = *max_element(v.begin(), v.end());
		int min = *min_element(v.begin(), v.end());
		cout << "#" << k + 1 << " " << max - min << endl;
	}
}

//25.10.17. 10:45 finish