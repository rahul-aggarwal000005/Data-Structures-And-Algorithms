#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int b[], int n, int m) {
	int ans = 0;
	int first = 0;
	int second = 0;
	int i = 0;
	for (int j = 0; j < m; j++) {
		second += b[j];
		while (i < n and a[i] < b[j]) {
			first += a[i];
			i++;
		}

		if (i < n and a[i] == b[j]) {
			first += a[i];
			ans += max(first, second);

			first = 0;
			second = 0;
			i++;
		}
	}

	while (i < n) {
		first += a[i];
		i++;
	}

	ans += max(first, second);
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (true) {
		int x;
		cin >> x;
		if (x == 0) break;
		int n;
		n = x;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int m;
		cin >> m;
		int b[m];
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int ans = solve(a, b, n, m);
		cout << ans << endl;

	}
	return 0;
}