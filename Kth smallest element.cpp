#include<bits/stdc++.h>
using namespace std;

void randomPartition(vector<int> &arr, int s, int e) {

	int n = (e - s + 1);
	int r = rand() % n;
	swap(arr[s + r], arr[e]);
}

int partition(vector<int> &arr, int s, int e) {

	randomPartition(arr, s, e);
	int pivot = arr[e];
	int i = s;
	for (int j = s; j <= e - 1; j++) {
		if (arr[j] <= pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
	}

	swap(arr[i], arr[e]);
	return i;
}

int kthSmallest(vector<int>&arr, int s, int e, int k) {

	if (k > 0 and (e - s + 1) >= k) {
		int p = partition(arr, s, e);

		if (p - s + 1 == k) return arr[p];

		if (p - s + 1 > k) {
			return kthSmallest(arr, s, p - 1, k);
		}

		return kthSmallest(arr, p + 1, e, k - (p - s) - 1);
	}

	return INT_MAX;

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = kthSmallest(arr, 0, n - 1, k);
	cout << ans << endl;
	return 0;
}