#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int dx[4] = { 0,1,1,1 };
int dy[4] = { 1,0,-1,1 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		vector<char> v_t(n, '.');
		vector<vector<char>> v(n, v_t);
	

		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < str.size(); j++) {
				if (str[j] == 'o') {
					v[i][j] = 'o';
				}
			}

		}
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (found) {
				break;
			}
			for (int j = 0; j < n; j++) {
				if (found) {
					break;
				}
				if (v[i][j] != 'o') { continue; }
				for (int k = 0; k < 4; k++) {
					int cnt = 1;
					int nx = i + dx[k];
					int ny = j + dy[k];
					while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						if (v[nx][ny] == 'o') {
							nx += dx[k];
							ny += dy[k];
							cnt++;
						}
						else {
							break;
						}
					}
					if (cnt == 5) {
						found = true;
					}
				}
			}
		}
		if (found) {
			cout << "#" << t << " YES\n";
		}
		else {
			cout << "#" << t << " NO\n";
		}
	}
	return 0;
}