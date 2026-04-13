#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(vector<vector<int>>& v, 
	vector<vector<bool>>& visited, pair<int, int> sp,
	int n, int m) {

	queue<pair<int,int>> q;
	q.push(sp);
	visited[sp.first][sp.second] = true;
	v[sp.first][sp.second] = 0;
	while (!q.empty()) {
		int x, y;
		
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			x = cur.first + dx[i];
			y = cur.second + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m) {
				continue;
			}
			else {
				if (!visited[x][y] && v[x][y] == 1) {
					visited[x][y] = true;
					q.push({ x, y });
					v[x][y] = v[cur.first][cur.second] + 1;
				}
			}
		}
		
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> v(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	pair<int, int> sp = { 0,0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			v[i][j] = tmp;
			if (tmp == 2) {
				sp = { i,j };
			}
		}
		
	}

	bfs(v, visited, sp, n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) {
				cout << v[i][j] << " ";
			}
			else {
				if (v[i][j] == 0) {
					cout << 0 << " ";
				}
				else {
					cout << -1 << " ";
				}
			}
			
		}
		cout << endl;
	}

	return 0;
}