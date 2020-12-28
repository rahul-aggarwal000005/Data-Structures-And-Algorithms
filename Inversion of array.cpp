#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int s, int e, int mid) {
	int i = s;
	int j = mid + 1;
	vector<int> temp(e - s + 1);
	int c = 0;
	int k = s;
	while (i <= mid and j <= e) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			c += (mid - i + 1);
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= e) {
		temp[k++] = arr[j++];
	}

	for (int i = s; i <= e; i++) {
		arr[i] = temp[i];
	}
	return c;
}

int count(vector<int> &arr, int s, int e) {
	if (s >= e) return 0;

	int mid = (s + e) / 2;
	int inversion = 0;
	inversion += count(arr, s, mid);
	inversion += count(arr, mid + 1, e);
	inversion += merge(arr, s, e, mid);
	return inversion;
}

long long inversionCount(vector<int> &arr) {
	return count(arr, 0, arr.size() - 1);
}

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

	long long ans = inversionCount(arr);
	cout << ans << endl;

	return 0;
}