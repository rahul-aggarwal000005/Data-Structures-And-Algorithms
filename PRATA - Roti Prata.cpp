#include <bits/stdc++.h>
using namespace std;

bool canMade(vector<int> &arr, int n, int p, int time) {
	int parathas = 0;
	for (int i = 0; i < n; i++) {
		// ith cook cooks p parathas
		int x = 0;
		int t = 0;
		int rank = arr[i];
		while (t + (x + 1)*rank <= time) {
			x++;
			t += x * arr[i];
		}
		parathas += x;
	}


	return parathas >= p;
}

int solve(vector<int> &arr, int p) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	int s = 0;
	int e = 0;
	for (int i = 1; i <= p; i++) {
		e = e + arr[n - 1] * p;
	}
	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (canMade(arr, n, p, mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
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
		int p, n;
		cin >> p >> n;
		vector<int> rank(n);
		for (int i = 0; i < n; i++) {
			cin >> rank[i];
		}
		int ans = solve(rank, p);
		cout << ans << endl;
	}
	return 0;
}