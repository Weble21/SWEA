#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int,int> &b) {
	if (a.second < b.second) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> v;

	for (int i = 0; i < k; i++) {
		int like, lev;
		cin >> like >> lev;
		v.push_back({ like, lev });
	}
	sort(v.begin(), v.end(), comp);

	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	
	for (int i = 0; i < k; i++) {
		int like = v[i].first;
		int level = v[i].second;

		pq.push(like);
		sum += like;

		if (pq.size() > n) {
			sum -= pq.top();
			pq.pop();
		}
		if (pq.size() == n && sum >= m) {
			cout << level << endl;
			return 0;
		}

	}
	cout << -1;
	return 0;
	

}