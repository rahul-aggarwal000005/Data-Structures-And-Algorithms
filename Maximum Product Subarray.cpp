#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int arr[], int n) {

	long long ans = arr[0];
	long long maxVal = arr[0];
	long long minVal = arr[0];

	for (int i = 1; i < n; i++) {

		if (arr[i] < 0) {
			swap(maxVal, minVal);
		}

		maxVal = max((long long)(arr[i]), maxVal * arr[i]);
		minVal = min((long long)(arr[i]), minVal * arr[i]);
		ans = max(ans, maxVal);
	}
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
		N = 5
		Arr[] = {6, -3, -10, 0, 2}
	*/

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long ans = maxProduct(arr, n);
	cout << ans << endl;
	return 0;
}