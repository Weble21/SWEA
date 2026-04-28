#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {

		string str;
		cin >> str;
		
		vector<bool> x(2, false);
		vector<bool> y(2, false);

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'S') {
				y[0] = true;
			}
			else if (str[i] == 'N') {
				y[1] = true;
			}
			else if (str[i] == 'W') {
				x[0] = true;
			}
			else if (str[i] == 'E') {
				x[1] = true;
			}
		}

		if (x[1] == x[0] && y[0] == y[1]) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}