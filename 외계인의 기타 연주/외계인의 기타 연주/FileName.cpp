#include <iostream>
#include <stack>

using namespace std;


stack<int> s1, s2, s3, s4, s5, s6;

void stack_1(stack<int>& s1, int plat, int &cnt) {
	while (true) {
		if (!s1.empty()) {

			if (s1.top() == plat) {
				break;
			}

			if (s1.top() < plat) {
				s1.push(plat);
				cnt++;
			} else {
				s1.pop();
				cnt++;
			}

		}
		else {
			s1.push(plat);
			cnt++;
		}

	}
}
void stack_2(stack<int>& s2, int plat, int& cnt) {
	while (true) {
		if (!s2.empty()) {

			if (s2.top() == plat) {
				break;
			}

			if (s2.top() < plat) {
				s2.push(plat);
				cnt++;
			}
			else {
				s2.pop();
				cnt++;
			}

		}
		else {
			s2.push(plat);
			cnt++;
		}

	}
}
void stack_3(stack<int>& s3, int plat, int& cnt) {
	while (true) {
		if (!s3.empty()) {

			if (s3.top() == plat) {
				break;
			}

			if (s3.top() < plat) {
				s3.push(plat);
				cnt++;
			}
			else {
				s3.pop();
				cnt++;
			}

		}
		else {
			s3.push(plat);
			cnt++;
		}

	}
}
void stack_4(stack<int>& s4, int plat, int& cnt) {
	while (true) {
		if (!s4.empty()) {

			if (s4.top() == plat) {
				break;
			}

			if (s4.top() < plat) {
				s4.push(plat);
				cnt++;
			}
			else {
				s4.pop();
				cnt++;
			}

		}
		else {
			s4.push(plat);
			cnt++;
		}

	}
}
void stack_5(stack<int>& s5, int plat, int& cnt) {
	while (true) {
		if (!s5.empty()) {

			if (s5.top() == plat) {
				break;
			}

			if (s5.top() < plat) {
				s5.push(plat);
				cnt++;
			}
			else {
				s5.pop();
				cnt++;
			}

		}
		else {
			s5.push(plat);
			cnt++;
		}

	}
}
void stack_6(stack<int>& s6, int plat, int& cnt) {
	while (true) {
		if (!s6.empty()) {

			if (s6.top() == plat) {
				break;
			}

			if (s6.top() < plat) {
				s6.push(plat);
				cnt++;
			}
			else {
				s6.pop();
				cnt++;
			}

		}
		else {
			s6.push(plat);
			cnt++;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int num, plat;
		cin >> num >> plat;
		if (num == 1) {
			stack_1(s1, plat, cnt);
		}
		else if (num == 2) {
			stack_2(s2, plat, cnt);
		}
		else if (num == 3) {
			stack_3(s3, plat, cnt);
		}
		else if (num == 4) {
			stack_4(s4, plat, cnt);
		}
		else if (num == 5) {
			stack_5(s5, plat, cnt);
		}
		else if (num == 6) {
			stack_6(s6, plat, cnt);
		}


	}
	cout << cnt;
}