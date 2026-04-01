#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		mp.insert({ str, i });
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(mp[str]);
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] > v[j]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}