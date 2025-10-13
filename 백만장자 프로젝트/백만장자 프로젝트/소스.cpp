#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

//20.10.13. 21:36 start
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cin.ignore();

		string s;
		getline(cin, s);

		stringstream ss(s);
		deque<int> arr;
		
		int num;
		while (ss >> num) {
			arr.push_back(num);
		}

		long long sum = 0;
		while (!arr.empty()) {

			int max = arr.front();
			int max_key = 0;
			for (int k = 1; k < arr.size(); k++) {
				if (arr[k] > max) {
					max = arr[k];
					max_key = k;
				}
			}
			
			for (int k = 0; k <= max_key; k++) {
				int tmp = max - arr.front();
				sum += tmp;
				arr.pop_front();
			}
			

		}
		cout << "#" << i+1 << " " << sum << endl;
	}

	
	return 0;
}

//25.10.13. 10:30 finish