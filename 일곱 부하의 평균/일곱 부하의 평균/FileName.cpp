#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		vector<int> v;
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
			v.push_back(tmp);
		}
		int max = *max_element(v.begin(), v.end());
		max += 1;
		sum += max;
		if (sum % 7 == 0) {
			cout << max << endl;
		}
		else {
			int rest = sum % 7;
			
			max = max + (7 - rest);
			cout << max << endl;
		}
		
	}
}