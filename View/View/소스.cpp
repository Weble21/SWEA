#include <iostream>

using namespace std;

//25.10.15. 21:24 start

int find_min(int a, int b, int c, int d) {
	int min = 256;
	if (a < min) {
		min = a;
	}
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	if (d < min) {
		min = d;
	}

	if (min > 0) {
		return min;
	}
	else {
		min = 0;
		return min;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int k = 0; k < 10; k++) {
		int t;
		cin >> t;
		int* arr = new int[t - 1];
		for (int i = 0; i < t; i++) {
			cin >> arr[i];
		}

		int sum = 0;
		for (int i = 2; i < t - 2; i++) {
			
			int a = arr[i] - arr[i - 1];
			int b = arr[i] - arr[i - 2];
			int c = arr[i] - arr[i + 2];
			int d = arr[i] - arr[i + 1];
			int res = find_min(a, b, c, d);
			sum += res;
		}
		cout << "#" << k + 1 << " " << sum << endl;
	}
}
//25.10.15. 21:56 finish