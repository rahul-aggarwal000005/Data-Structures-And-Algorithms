#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n, int x) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == x) {
			ans = mid;
			e = mid - 1;
		}
		else if (arr[mid] > x) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int lastOccurence(int arr[], int n, int x) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == x) {
			ans = mid;
			s = mid + 1;
		}
		else if (arr[mid] > x) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
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
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int first = firstOccurence(arr, n, x);
		int last = lastOccurence(arr, n, x);
		if (first == -1) {
			cout << "-1\n";
		}
		else {
			cout << first << " " << last << endl;
		}
	}
	return 0;
}