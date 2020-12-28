#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(vector<int> &arr, int n) {

	unordered_map<int, int> mp;

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];

		if (mp.find(sum) != mp.end() or sum == 0) return true;
		mp[sum]++;
	}
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
		5
		4 2 -3 1 6
	*/

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (subArrayExists(arr, n)) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}