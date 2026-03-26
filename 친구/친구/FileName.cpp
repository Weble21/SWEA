#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'Y') {
				v[i].push_back(j);
			}
		}
	}
	
	vector<int> res(n, 0);
	for (int i = 0; i < n; i++) {
		vector<bool> check(n, false);
		for (int j = 0; j < v[i].size(); j++) {
			check[v[i][j]] = true;
		}
		int cnt = 0;
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = 0; k < v[v[i][j]].size(); k++) {
				check[v[v[i][j]][k]] = true;
			}
			
		}
		check[i] = false;
		for (int j = 0; j < n; j++) {
			if (check[j]) {
				cnt++;
			}
		}
		res[i] = cnt;
		//cout << "res[" << i << "] : " << res[i] << endl;
	} 

	int result = *max_element(res.begin(), res.end());

	cout << result;
	
}