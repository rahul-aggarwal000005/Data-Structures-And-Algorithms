#include <bits/stdc++.h>
using namespace std;

int median(vector<int> &v) {
	sort(v.begin(), v.end());
	int n = v.size();
	if (n & 1) {
		return v[n / 2];
	}
	else {
		int mid = v[n / 2 - 1] + v[n / 2];
		return mid / 2;
	}
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
	int med = median(arr);
	cout << med << endl;
	return 0;
}