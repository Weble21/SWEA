#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 100;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	for (int i = 0; i < 10; i++) {
		cin >> tc;
		vector<int> v1(SIZE, 0);
		vector<vector<int>> v(SIZE, v1) ;

		vector<int> row(100, 0);
		vector<int> col(100, 0);
		
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				int tmp;
				cin >> tmp;
				v[j][k] = tmp;
			}
		}

		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				row[j] += v[j][k];
			}
		}
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				col[j] += v[k][j];
			}
		}
		int mainDiag = 0;
		int antiDiag = 0;
		for (int j = 0; j < SIZE; j++) {
			mainDiag += v[j][j];
			antiDiag += v[j][SIZE - 1 - j];
		}
		int max1 = *max_element(row.begin(), row.end());
		int max2 = *max_element(col.begin(), col.end());
		int result1 = max(max1, max2);
		int result2 = max(mainDiag, antiDiag);
		int res = max(result1, result2);

		cout << "#" << tc << " " << res << "\n";

	} 
}