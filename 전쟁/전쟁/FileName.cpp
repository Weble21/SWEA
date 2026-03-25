#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int bluePower = 0;
int whitePower = 0;

int dir_x[4] = { -1, 0, 0, 1 };
int dir_y[4] = { 0, -1, 1, 0 };

int dfs_w(vector<vector<bool>>& chk, vector<vector<char>> &v, int n, int m, int i, int j) {
	if (v[i][j] != 'W') {
		return 0;
	}

	stack<pair<int, int>> s;
	pair<int, int> cur = { i, j };
	int res = 1;
	s.push(cur);
	chk[cur.first][cur.second] = true;
	while (!s.empty()) {
		pair<int, int> nx;
		nx = s.top();
		s.pop();
		for (int k = 0; k < 4; k++) {
			int ni = nx.first + dir_y[k];
			int nj = nx.second + dir_x[k];
			if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
				if (!chk[ni][nj] && v[ni][nj] == 'W') {
					chk[ni][nj] = true;
					s.push({ ni, nj });
					res++;
				}
			}
		}
	}
	return res;
}

int dfs_b(vector<vector<bool>> &chk, vector<vector<char>> &v, int n, int m, int i, int j) {
	if (v[i][j] != 'B') {
		return 0;
	}

	stack<pair<int, int>> s;
	pair<int, int> cur = { i, j };
	int res = 1;
	s.push(cur);
	chk[cur.first][cur.second] = true;
	while (!s.empty()) {
		pair<int, int> nx;
		nx = s.top();
		s.pop();
		for (int k = 0; k < 4; k++) {
			int ni = nx.first + dir_y[k];
			int nj = nx.second + dir_x[k];
			if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
				if (!chk[ni][nj] && v[ni][nj] == 'B') {
					chk[ni][nj] = true;
					s.push({ ni, nj });
					res++;				
				}
			}
		}
	}
	return res;
		
	
}

int pow(int a) {
	return a * a;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(m, vector<char>(n, 'o'));
	vector<vector<bool>> chk(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			v[i][j] = str[j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				if (v[i][j] == 'W') {
					whitePower = whitePower + pow(dfs_w(chk, v, n, m, i, j));
				}
				else {
					bluePower = bluePower + pow(dfs_b(chk, v, n, m, i, j));
				}
			}
		}
	}
	cout << whitePower << " " << bluePower;
}