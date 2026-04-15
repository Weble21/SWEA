#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<long long>> v(101, vector<long long>(10, 0));

	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			v[1][i] = 0;
		}
		else {
			v[1][i] = 1;
		}
		
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j != 0 && j != 9) {
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j + 1];
				
			}
			else {
				if (j == 0) {
					v[i][j] = v[i - 1][j + 1];
				}
				else {
					v[i][j] = v[i - 1][j - 1];
				}
			}
			
			
		}
	}

	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}*/

	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += v[n][i];
	}
	cout << result % 1000000000;
}