#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; 
	cin >> t;
	for (int i = 0; i < t; i++) {
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
		}
		double res = double(sum / 10.0);
		res = round(res);
		cout << "#" << i+1 << " " << res << endl;

	}
}