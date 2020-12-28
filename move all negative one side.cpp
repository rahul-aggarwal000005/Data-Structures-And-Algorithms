#include <bits/stdc++.h>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// -12, 11, -13, -5, 6, -7, 5, -3, -6
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0;
	int neg = 0;
	while (i < n) {
		if (arr[i] < 0) {
			swap(arr[i], arr[neg]);
			neg++;
		}
		i++;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}