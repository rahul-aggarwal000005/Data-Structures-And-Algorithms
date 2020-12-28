#include <bits/stdc++.h>
using namespace std;

void next_perumtation(vector<int> &nums) {

	int n = nums.size();
	int i = n - 2;
	while (i >= 0 and nums[i] >= nums[i + 1]) {
		i--;
	}

	if (i == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}

	int current = nums[i];
	int idx = n - 1;
	for (idx = n - 1; idx >= i; idx--) {
		if (nums[idx] > current) {
			break;
		}
	}

	swap(nums[idx], nums[i]);

	reverse(nums.begin() + i + 1, nums.end());

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	next_perumtation(nums);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}