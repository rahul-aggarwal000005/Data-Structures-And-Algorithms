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

	// 2 0 1 2 2 1 0

	int l = 0;
	int h = n - 1;
	int mid = 0;

	while (mid <= h) {

		if (arr[mid] == 0) {
			swap(arr[l], arr[mid]);
			l++;
			mid++;
		}

		else if (arr[mid] == 1) {
			mid++;
		}

		else if (arr[mid] == 2) {
			swap(arr[h], arr[mid]);
			h--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}