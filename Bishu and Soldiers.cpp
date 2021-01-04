#include <bits/stdc++.h>
using namespace std;

#define ll long long

int getSum(vector<int> &arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}
int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int round;
	cin >> round;
	int sum = 0;
	while (round--) {
		int power;
		cin >> power;
		int killed = upper_bound(arr.begin(), arr.end(), power) - arr.begin();
		int sum = getSum(arr, killed);
		cout << killed << " " << sum << endl;
	}

	return 0;
}