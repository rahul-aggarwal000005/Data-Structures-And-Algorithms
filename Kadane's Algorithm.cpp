#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int maxSum = INT_MIN;
	int currentSum = 0;
	for (int i = 0; i < n; i++) {
		currentSum += arr[i];
		maxSum = max(maxSum, currentSum);

		if (currentSum < 0) currentSum = 0;
	}

	cout << maxSum << endl;
	return 0;
}