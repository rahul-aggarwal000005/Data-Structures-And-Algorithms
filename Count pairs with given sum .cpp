#include <bits/stdc++.h>
using namespace std;

int getPairsCount(vector<int> &arr, int n, int k) {
	unordered_map<int, int> mp;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cnt += mp[k - arr[i]];

		if (k - arr[i] == arr[i]) cnt--;
	}

	return cnt / 2;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int count = getPairsCount(arr, n, k);
	cout << count << endl;
	return 0;
}