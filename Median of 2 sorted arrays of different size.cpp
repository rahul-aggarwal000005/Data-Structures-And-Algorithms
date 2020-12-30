#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &nums1, vector<int> &nums2) {
	if (nums1.size() > nums2.size()) {
		return median(nums2, nums1);
	}

	int lengthA = nums1.size();
	int lengthB = nums2.size();

	int s = 0;
	int e = lengthA;
	while (s <= e) {

		int partitionA = (s + e) / 2;
		int partitionB = (lengthA + lengthB + 1) / 2 - partitionA;

		int maxLeftA = partitionA == 0 ? INT_MIN : nums1[partitionA - 1];
		int minRightA = partitionA == lengthA ? INT_MAX : nums1[partitionA];

		int maxLeftB = partitionB == 0 ? INT_MIN : nums2[partitionB - 1];
		int minRightB = partitionB == lengthB ? INT_MAX : nums2[partitionB];

		if (maxLeftA <= minRightB and maxLeftB <= minRightA) {
			if ((lengthA + lengthB) & 1) {
				return (double)(max(maxLeftA, maxLeftB));
			}
			else {
				double l = (double)(max(maxLeftA, maxLeftB));
				double r = (double)(min(minRightA, minRightB));
				return (double)(l + r) / 2.0;
			}
		}
		else if (maxLeftA > minRightB) {
			e = partitionA - 1;
		} else {
			s = partitionA + 1;
		}
	}

	return INT_MAX;

}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> nums1(n);
	for (int i = 0; i < n; i++) {
		cin >> nums1[i];
	}
	int m;
	cin >> m;
	vector<int> nums2(m);
	for (int i = 0; i < m; i++) {
		cin >> nums2[i];
	}

	double med = median(nums1, nums2);
	cout << med << endl;
	return 0;
}