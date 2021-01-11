#include <bits/stdc++.h>
using namespace std;

bool isPal(int n) {
	string x = to_string(n);
	reverse(x.begin(), x.end());
	return  x == to_string(n);
}

int PalinArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (!isPal(a[i])) {
			return 0;
		}
	}
	return 1;
}

int main() {

#ifndef ONLINE_JUDGE
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

		cout << PalinArray(arr, n) << endl;
	}

	return 0;
}