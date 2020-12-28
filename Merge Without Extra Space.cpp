#include <bits/stdc++.h>
using namespace std;

int findGap(int gap) {
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int n, int m) {

	int i, j, gap = n + m;
	for (gap = findGap(gap); gap > 0; gap = findGap(gap)) {
		// in first array
		for (i = 0; i + gap < n; i++) {
			if (arr1[i] > arr1[i + gap]) {
				swap(arr1[i], arr1[i + gap]);
			}
		}

		// in both array
		for (j = gap > n ? gap - n : 0; i < n and j < m; j++, i++) {
			if (arr1[i] > arr2[j]) {
				swap(arr1[i], arr2[j]);
			}
		}

		// in second array
		if (j < m) {
			for (j = 0; j + gap < m; j++) {
				if (arr2[j] > arr2[j + gap]) {
					swap(arr2[j], arr2[j + gap]);
				}
			}
		}
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int arr1[n];
	int arr2[m];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	merge(arr1, arr2, n, m);
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << arr2[i] << " ";
	}
	return 0;
}