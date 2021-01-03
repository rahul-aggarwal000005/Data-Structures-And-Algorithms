#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long countTriplets(long long arr[], long long n, long long sum) {
	long long count = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1;
		int right = n - 1;
		while (left < right) {
			int x = arr[i] + arr[left] + arr[right];
			if (x >= sum) {
				right--;
			}
			else {
				count += (right - left);
				left++;
			}
		}
	}
	return count;
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
		long long arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long ans = countTriplets(arr, n, x);
		cout << ans << endl;
	}
	return 0;
}