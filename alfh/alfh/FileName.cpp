#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

pair<int, int> tmp;
int dx[4] = { 0, 1, 0,-1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int n, vector<vector<int>> &v, vector<vector<bool>> &chk) {
	queue<pair<int, int>> s;
	s.push(tmp);
	while (!s.empty()) {
		int cur_x = s.front().first;
		int cur_y = s.front().second;
		
		
		s.pop();
		for (int i = 0; i < 4; i++) {
			
			int nx = dx[i] + cur_x;
			int ny = dy[i] + cur_y;
			if (nx >= n || ny >= n || nx < 0 || ny < 0) {
				continue;
			} else {
				if (v[nx][ny] == 3) {
					return true;
				}
				if (chk[nx][ny]) {
					continue;
				}
				else {
					
					if (v[nx][ny] == 0) {
						
						pair<int, int> cur = { nx, ny };
						s.push(cur);
						
						chk[nx][ny] = true;
					}
					
				}

			}
			
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	
	for (int k = 0; k < 10; k++) {
		int n;
		int t;
		n = 16;
		vector<int> v1(n, -1);
		vector<vector<int>> v(n, v1);
		vector<bool> chk1(n, true);
		vector<vector<bool>> chk(n, chk1);
		cin >> t;
		for (int i = 0; i < n; i++) {
		
			string str;
			cin >> str;
			for (int j = 0; j < str.size(); j++) {
				v[i][j] = str[j] - '0';
				if (v[i][j] != 1) {
					chk[i][j] = false;
				}

				if(v[i][j] == 2) {
					tmp.first = i;
					tmp.second = j;			
				}
				
			}
		
		}
		if (dfs(n, v, chk)) {
			cout << "#" << t << " 1\n";
		}
		else {
			cout << "#" << t << " 0\n";
		}
		
	}
}