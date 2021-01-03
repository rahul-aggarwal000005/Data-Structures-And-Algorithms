#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> fourSum(vector<int> &arr, int k) {

	vector<vector<int>> res;
	set<vector<int>> s;
	int n = arr.size();
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 1; j < n - 2; j++) {
			int left = j + 1;
			int right = n - 1;
			while (left < right) {
				int sum = arr[i] + arr[j] + arr[left] + arr[right];
				if (sum == k) {
					s.insert({arr[i], arr[j], arr[left], arr[right]});
					right--;
					left++;
				}
				else if (sum > k) {
					right--;
				}
				else {
					left++;
				}
			}
		}
	}
	for (auto x : s) {
		res.push_back(x);
	}
	return res;
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
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<vector<int>> ans = fourSum(arr, x);
		cout << ans.size() << endl;
	}
	return 0;
}