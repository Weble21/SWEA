#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool fun(string str) {
	int n = str.size();
	if (n == 2) {
		if (str[0] == str[1]) {
			return true;
		}
		else {
			return false;
		}
	}
	for (int i = 0; i != (n-1)/2; i++) {
		if (str[i] == str[n - i - 1]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

bool fun(vector<char> str) {
	int n = str.size();
	if (n == 2) {
		if (str[0] == str[1]) {
			return true;
		}
		else {
			return false;
		}
	}
	for (int i = 0; i != (n - 1) / 2; i++) {
		if (str[i] == str[n - i - 1]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string str;
		cin >> str;
		int n = str.size();
		vector<char> str_front;
		vector<char> str_back;
		for (int i = 0; i < (n - 1) / 2; i++) {
			str_front.push_back(str[i]);
		}
		for (int i = ((n - 1) / 2) + 1; i < n; i++) {
			str_back.push_back(str[i]);
		}
		

		string result;
		if (fun(str)) {
			if (fun(str_front)) {
				if (fun(str_back)) {
					result = " YES";
				}
				else {
					result = " NO";
				}
			}
			else {
				result = " NO ";
			}
		}
		else {
			result = " NO";
		}

		cout << "#" << t << result << "\n";
	}

	return 0;
}