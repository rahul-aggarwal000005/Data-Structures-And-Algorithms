#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll findSubarray(vector<ll> &arr, int n) {

	ll sum = 0;
	ll cnt = 0;
	unordered_map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
		if (sum == 0) {
			cnt++;
		}
		if (mp.find(sum) != mp.end()) {
			cnt = cnt + mp[sum];
		}
		mp[sum]++;
	}
	return cnt;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*
		6
		{0,0,5,5,0,0}
	*/
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = findSubarray(arr, n);
	cout << ans << endl;
	return 0;
}