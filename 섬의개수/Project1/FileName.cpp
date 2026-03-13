#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int w, h;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(vector<vector<int>> &v, vector<vector<bool>> &chk, int x, int y) {
	
	if ((x < 0 || x >= h || y < 0 || y >= w)) {
		return;
	}
	if (chk[x][y]) {
		return;
	}
	chk[x][y] = true;
	if (v[x][y] == 0) {
		return;
	}
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(v, chk, nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (true) {
		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}
		vector<vector<int>> v(h, vector<int>(w));
		vector<vector<bool>> chk(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> v[i][j];
				
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (v[i][j] == 1 && !chk[i][j]) {
					dfs(v, chk, i, j);
					cnt++;
				}
			}
		}
		
		
		cout << cnt << "\n";
	}
	
}