#include <bits/stdc++.h>
using namespace std;

int rainWater(vector<int> &arr) {

	int n = arr.size();

	vector<int> left(n);
	vector<int> right(n);

	left[0] = arr[0];
	right[n - 1] = arr[n - 1];

	for (int i = 1; i < n; i++) {
		left[i] = max(left[i - 1], arr[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		right[i] = max(right[i + 1], arr[i]);
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		total = total + (min(left[i], right[i]) - arr[i]);
	}

	return total;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int result = rainWater(arr);
		cout << result << endl;
	}
	return 0;
}