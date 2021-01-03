#include <bits/stdc++.h>
using namespace std;

#define ll long long

int difference(vector<int> &arr, int x) {
	unordered_map<int, int> mp;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		mp[arr[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		int cur = arr[i] + x;
		if (mp.find(cur) != mp.end() and mp[cur] != i) {
			return 1;
		}
	}
	return -1;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int ans = difference(arr, x);
		cout << ans << endl;
	}
	return 0;
}