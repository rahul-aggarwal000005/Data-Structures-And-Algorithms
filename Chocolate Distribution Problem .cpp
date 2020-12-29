#include <bits/stdc++.h>
using namespace std;

int distribute(vector<int> &arr, int m) {
	sort(arr.begin(), arr.end());
	int n = arr.size();
	int i = 0;
	int j = m - 1;
	int minDifference = arr[j] - arr[i];
	while (j < n) {
		minDifference = min(minDifference, arr[j] - arr[i]);
		i++;
		j++;
	}
	return minDifference;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cin >> m;
		int ans = distribute(arr, m);
		cout << ans << endl;
	}
	return 0;
}