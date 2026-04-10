#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };



int bfs(vector<vector<int>> &v,
	vector<vector<bool>>& visited, int n, int m) {
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				continue;
			}
			if (!visited[ny][nx] && v[ny][nx] == 1) {
				visited[ny][nx] = true;
				v[ny][nx] = v[y][x] + 1;
				q.push({ ny, nx });
			}
		}

	}
	return v[n - 1][m - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '1') {
				v[i][j] = 1;
			}
			else {
				v[i][j] = 0;
			}
		}
	}

	int res = bfs(v, visited, n, m);

	cout << res;


}