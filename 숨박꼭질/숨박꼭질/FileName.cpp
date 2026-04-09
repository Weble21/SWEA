#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	int res = 0;
	queue<int> q;
	int arr[3] = { -1, 1, 2 };
	bool visited[100001] = { false, };
	q.push(n);
	visited[n] = true;
	while (1) {
		vector<int> v;
		res++;
		while (!q.empty()) {
			v.push_back(q.front());
			q.pop();
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < 3; j++) {

				int tmp;
				if (j != 2) {
					tmp = v[i] + arr[j];
				}
				else {
					tmp = v[i] * arr[j];
				}

				if (tmp < 100001 && tmp >= 0 && !visited[tmp]) {
					visited[tmp] = true;
					q.push(tmp);
				}
			

			}
		}
		
		if (visited[k]) {
			cout << res;
			return 0;
		}
		else {
			continue;
		}

	}

}
