#include <bits/stdc++.h>
using namespace std;

#define ll long long

int pivotElement(int arr[], int n) {
	int s = 0;
	int e = n - 1;
	int peak = -1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (mid == 0) {
			if (mid == e) {
				return arr[mid];
			}
			else if (arr[mid] >= arr[mid + 1]) {
				return arr[mid];
			}
			else return -1;
		}
		else if (mid == e) {
			if (mid == s) {
				return arr[mid];
			}
			else if (arr[mid] >= arr[mid - 1]) {
				return arr[mid];
			}
			else return -1;
		}
		else {
			if (arr[mid] >= arr[mid + 1] and arr[mid] >= arr[mid - 1]) {
				return mid;
			}
			else if (arr[mid] > arr[e]) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	}
	return peak;
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
	int peak = pivotElement(arr, n);
	cout << peak;

	return 0;
}