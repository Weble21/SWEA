#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n, k;
		cin >> n >> k;
		vector<bool> v(n+1, false);
		for (int i = 0; i < k; i++) {
			int tmp;
			cin >> tmp;
			v[tmp] = true;
		}
		vector<int> res;
		for (int i = 1; i < v.size(); i++) {
			if (!v[i]) {
				res.push_back(i);
			}
		}
		cout << "#" << t << " ";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}