#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int a, b;
		int plus, minus;
		cin >> plus >> minus;
		b = (plus - minus) / 2;
		a = plus - b;
		cout << a << " " << b;
	}
	return 0;
}