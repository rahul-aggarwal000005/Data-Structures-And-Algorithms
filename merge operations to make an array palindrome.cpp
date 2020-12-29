#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef Rahul
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 0, j = n - 1; i < j;) {
		if (arr[i] == arr[j]) {
			i++;
			j--;
		}
		else if (arr[i] > arr[j]) {
			j--;
			ans++;
			arr[j] = arr[j] + arr[j + 1];
		}
		else {
			i++;
			ans++;
			arr[i] = arr[i] + arr[i - 1];
		}
	}
	cout << ans << endl;
	return 0;
}