#include <bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n) {
	unordered_map<int, int> mp;
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
		mp[arr[i]] = i;
	}
	sort(temp.begin(), temp.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != temp[i]) {
			ans++;
			int init = arr[i];
			swap(arr[i], arr[mp[temp[i]]]);
			mp[init] = mp[temp[i]];
			mp[temp[i]] = i;
		}
	}
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = minSwaps(arr, n);
	cout << ans << endl;
	return 0;
}