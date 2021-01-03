#include <bits/stdc++.h>
using namespace std;

#define ll long long

int maxLoot(vector<int> &arr) {
	int n = arr.size();
	if (n == 1) return arr[0];
	if (n == 2) return max(arr[0], arr[1]);
	int dp[n + 1] = {0};
	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
	}

	return dp[n - 1];
}

int main() {

#ifndef ONLINE
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
		int ans = maxLoot(arr);
		cout << ans << endl;
	}
	return 0;
}