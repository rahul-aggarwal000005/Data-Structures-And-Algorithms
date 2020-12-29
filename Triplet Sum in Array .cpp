#include <bits/stdc++.h>
using namespace std;


bool isTriplet(vector<int> &arr, int x) {

	int n = arr.size();
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n - 2; i++) {
		int cur = arr[i];
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			if (arr[i] + arr[j] + arr[k] == x) return true;

			if (arr[i] + arr[j] + arr[k] > x) {
				k--;
			}
			else {
				j++;
			}
		}
	}

	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (isTriplet(arr, k)) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}

	return 0;
}