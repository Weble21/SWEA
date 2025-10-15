#include <iostream>

using namespace std;

//25.10.15. 22:24 start
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int test_num;
		cin >> test_num;

		int arr[101] = { 0, };
		for (int i = 0; i < 1000; i++) {
			int tmp;
			cin >> tmp;
			arr[tmp]++;
		}

		int max = 0;
		int score = 0;
		for (int i = 100; i >= 0; i--) {
			if (arr[i] > max) {
				max = arr[i];
				score = i;
			}
		}
		cout << "#" << test_num << " " << score << endl;
	}
}