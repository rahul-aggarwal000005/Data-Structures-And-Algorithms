#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool canPlace(vector<int> &arr, int n, int c, int dist) {
	int cnt = 1;
	int last = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - last >= dist) {
			last = arr[i];
			cnt++;
		}
	}
	return cnt >= c;
}

int solve(vector<int> &arr, int n, int c) {

	sort(arr.begin(), arr.end());
	int x0 = arr[0];
	int xn = arr[n - 1];
	int s = 1;
	int e = xn - x0;
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (canPlace(arr, n, c, mid)) {
			ans = max(ans, mid);
			s = mid + 1;

		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		vector<int> xi(n);
		for (int i = 0; i < n; i++) {
			cin >> xi[i];
		}
		int ans = solve(xi, n, c);
		cout << ans << endl;
	}
}