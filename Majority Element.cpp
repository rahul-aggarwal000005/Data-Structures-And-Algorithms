#include <bits/stdc++.h>
using namespace std;

#define ll long long

int majorityElement(int arr[], int n) {
	int element = -1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (count == 0) {
			element = arr[i];
		}
		if (element == arr[i]) {
			count++;
		}
		else {
			count--;
		}
	}

	count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == element) count++;
	}
	return count > n / 2 ? element : -1;
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
	int ans = majorityElement(arr, n);
	cout << ans << endl;
	return 0;
}