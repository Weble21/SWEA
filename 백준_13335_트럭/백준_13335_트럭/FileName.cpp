#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, w, L;
	cin >> n >> w >> L;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	int time = 0;
	queue<int> brd;
	int brdWeight = 0;
	while (!q.empty()) {
		if (brd.size() == w) {
			brdWeight -= brd.front();
			brd.pop();
			
		}
		if (brdWeight + q.front() > L) {
			brd.push(0);
		}
		else {
			brd.push(q.front());
			brdWeight += q.front();
			q.pop();
		}
	
	time++;
	}
	cout << time + w;
}