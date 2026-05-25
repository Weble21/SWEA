#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n, k;
		cin >> n >> k;
		vector<int> v1 (n, 0);
		vector<vector<int>> v(n, v1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		
		int res = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			int cnt_2 = 0;
			for (int j = 0; j < n; j++) {
				//가로
				if (v[i][j] == 1) {
					cnt++;
					
				}
				else {
					if (cnt == k) {
						res++;
					}
					cnt = 0;
				}
				
				//세로
				if (v[j][i] == 1) {
					cnt_2++;
					
				}
				else {
					if (cnt_2 == k) {
						res++;
					}
					cnt_2 = 0;
				}
				
			}
			if (cnt == k) res++;
			if (cnt_2 == k) res++;
			
		}
		cout << "#" << t << " " << res << "\n";
	}
}