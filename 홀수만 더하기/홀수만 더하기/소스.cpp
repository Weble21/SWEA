#include <iostream>
#include <string>
#include <sstream>

using namespace std;


//25.10.14. 18:42 start
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int arr[11] = {0};
		for (int j = 0; j < 10; j++) {
			cin >> arr[j];
		}
		
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			if ((arr[j] % 2) != 0) {
				sum += arr[j];
			}
		}

		cout << "#" << i+1 << " " << sum << endl;
	}

	return 0;
}
//25.10.14. 18:51 finish