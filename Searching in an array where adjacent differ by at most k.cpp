#include <bits/stdc++.h>
using namespace std;

#define ll long long

int search(int arr[], int n, int k, int x) {
	int i = 0;
	while (i < n) {
		if (arr[i] == x) return i;

		int leastDist = max(1, abs(arr[i] - x) / k);
		i = i + leastDist;
	}
	return -1;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k, x;
	cin >> n >> k >> x;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = search(arr, n, k, x);
	cout << ans << endl;
	return 0;
}