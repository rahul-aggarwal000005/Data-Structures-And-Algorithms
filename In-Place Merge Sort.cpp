#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e, int mid) {
	int i = s;
	int j = mid + 1;
	// check if the last element of the first part is less than or equal to first
	// element of second part. If it is then simply return
	if (arr[mid] <= arr[j]) return;

	while (i <= mid and j <= e) {
		if (arr[i] <= arr[j]) {
			i++;
		}
		else {
			int value = arr[j];
			int idx = j;
			while (idx != i) {
				arr[idx] = arr[idx - 1];
				idx--;
			}

			arr[idx] = value;
			mid++;
			i++;
			j++;
		}
	}

}

void mergeSort(int arr[], int s, int e) {
	if (s >= e) {
		return;
	}

	int mid = (s + e) / 2;
	mergeSort(arr, s, mid);
	mergeSort(arr, mid + 1, e);
	merge(arr, s, e, mid);
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, a, b;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}