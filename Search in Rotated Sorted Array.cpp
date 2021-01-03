#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target) {
	int n = nums.size();
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		if (nums[mid] >= nums[s]) {
			// its in the first part
			if (target >= nums[s] and target < nums[mid]) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		else {
			if (target <= nums[e] and target >= nums[mid]) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	}
	return -1;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, target;
	cin >> n >> target;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int ans = search(nums, target);
	cout << ans << endl;
	return 0;
}