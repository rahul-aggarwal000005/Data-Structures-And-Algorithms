#include <bits/stdc++.h>
using namespace std;

int sumGreater(int arr[], int n, int x) {
	int sum = 0;
	int s = 0;
	int e = 0;
	int ans = n + 1;
	while (e < n) {

		while (sum <= x and e < n) {
			sum += arr[e];
			e++;
		}

		while (sum > x and s < n) {
			ans = min(ans, (e - s));
			sum -= arr[s];
			s++;
		}
	}
	return ans;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int ans = sumGreater(arr, n, x);
		cout << ans << endl;

	}

	return 0;
}