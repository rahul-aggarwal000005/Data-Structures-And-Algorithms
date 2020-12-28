#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int n, int k) {
	// two pointer approach

	vector<pair<int, int>> a;
	vector<int> taken(n, 0);

	for (int i = 0; i < n; i++) {
		if (arr[i] - k >= 0) {
			a.push_back({arr[i] - k, i});
		}
		a.push_back({arr[i] + k, i});
	}

	sort(a.begin(), a.end());

	int count = 0;
	int left = 0;
	int right = 0;

	while (count < n and right < a.size()) {
		if (taken[a[right].second] == 0) {
			count++;
		}
		taken[a[right].second]++;
		right++;
	}

	int ans = a[right - 1].first - a[left].first;
	// now we will shrink the window
	while (right < a.size()) {

		if (taken[a[left].second] == 1) {
			count--;
		}

		taken[a[left].second]--;
		left++;

		while (count < n and right < a.size()) {
			if (taken[a[right].second] == 0) {
				count++;
			}
			taken[a[right].second]++;
			right++;
		}


		if (count == n) {
			ans = min(ans, a[right - 1].first - a[left].first);
		}
		else {
			break;
		}
	}

	return ans;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = getMinDiff(arr, n, k);
	cout << ans << endl;
	return 0;
}