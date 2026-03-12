#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int st, end;
	cin >> st >> end;
	int m;
	cin >> m;
	
	vector<vector<int>> v(n + 1);

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);

	}
	
	
	vector<int> distance(n+1, -1);
	distance[st] = 0;
	
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int cur = q.front();
		if (cur == end) {
			break;
		}
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int tmp = v[cur][i];
			if (distance[tmp] == -1) {
				q.push(tmp);
				distance[tmp] = distance[cur] + 1;
			}		
		}
		
	}
	cout << distance[end] << endl;

	
	
	return 0;
}