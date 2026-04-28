#include <iostream>

using namespace std;

const unsigned long long d = 998244353;

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		unsigned long long a, b, c;
		cin >> a >> b >> c;
	
		a = a * (a + 1) / 2;
		b = b * (b + 1) / 2;
		c = c * (c + 1) / 2;

		a %= d;
		b %= d;
		c %= d;
		
		a = a * b;
		a %= d;
		a = a * c;
		a %= d;

		cout << a << endl;
	}
}