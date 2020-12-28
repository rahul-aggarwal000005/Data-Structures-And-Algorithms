#include<bits/stdc++.h>
using namespace std;

int minimum(vector<int> &arr, int s, int e) {
	if (s > e) return INT_MAX;

	if (s == e) return arr[s];

	if (e == (s + 1)) return min(arr[s], arr[e]);

	int mid = (s + e) / 2;
	return min(minimum(arr, s, mid), minimum(arr, mid + 1, e));
}

int maximum(vector<int> &arr, int s, int e) {
	if (s > e) return INT_MIN;

	if (s == e) return arr[s];

	if (e == (s + 1)) return max(arr[s], arr[e]);

	int mid = (s + e) / 2;
	return max(maximum(arr, s, mid), maximum(arr, mid + 1, e));
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

	int minElement = minimum(arr, 0, n - 1);
	int maxElement = maximum(arr, 0, n - 1);
	cout << "minimum element : " << minElement << endl;
	cout << "maximum element : " << maxElement << endl;
	return 0;
}