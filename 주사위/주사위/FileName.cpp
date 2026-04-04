#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_of_arr_three(int arr[]) {
	int min;
	vector<int> v(8, 0);
	v[0] = arr[1] + arr[2] + arr[4];
	v[1] = arr[1] + arr[5] + arr[4];
	v[2] = arr[1] + arr[2] + arr[3];
	v[3] = arr[1] + arr[5] + arr[3];
	v[4] = arr[6] + arr[2] + arr[4];
	v[5] = arr[6] + arr[5] + arr[4];
	v[6] = arr[6] + arr[2] + arr[3];
	v[7] = arr[6] + arr[5] + arr[3];
	min = *min_element(v.begin(), v.end());

	return min;
}

int min_of_arr_two(int arr[]) {
	int min;
	vector<int> v(12, 0);
	v[0] = arr[1] + arr[4];
	v[1] = arr[1] + arr[3];
	v[2] = arr[1] + arr[2];
	v[3] = arr[1] + arr[5];
	v[4] = arr[2] + arr[6];
	v[5] = arr[6] + arr[5];
	v[6] = arr[6] + arr[4];
	v[7] = arr[6] + arr[3];
	v[8] = arr[2] + arr[4];
	v[9] = arr[4] + arr[5];
	v[10] = arr[5] + arr[3];
	v[11] = arr[2] + arr[3];
	min = *min_element(v.begin(), v.end());

	return min;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	

	int arr[7] = { 0, };
	for (int i = 1; i <= 6; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	if (n == 1) {
		int res;
		res = arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6];
		int max_arr = *max_element(arr, arr + 7);
		cout << res - max_arr;
		return 0;
	}

	//계산할 총면적
	long long all = n * n * 5;
	//3면
	long long three = 4;
	//2면
	long long two = ((n - 1) * 4) + ((n - 2) * 4);
	//1면
	long long one = all - three*3 - two*2;

	int min_of_arr = *min_element(arr + 1, arr + 7);

	long long result;
	long long three_result = three * min_of_arr_three(arr);
	long long two_result = two * min_of_arr_two(arr);
	long long one_result = one * min_of_arr;

	result = three_result + two_result + one_result;
	cout << result;
	
}