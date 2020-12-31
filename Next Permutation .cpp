#include<bits/stdc++.h>
using namespace std;

void nextPermutation(int arr[], int n) {
	int i = n - 2;
	while (i >= 0 and arr[i] >= arr[i + 1]) {
		i--;
	}

	if (i == -1) {
		reverse(arr, arr + n);
		return;
	}

	int val = arr[i];
	// find the next larger number from right
	int idx = n - 1;
	for (; idx >= i; idx--) {
		if (arr[idx] > val) {
			break;
		}
	}

	swap(arr[idx], arr[i]);
	reverse(arr + i + 1, arr + n);
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		nextPermutation(arr, n);
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}