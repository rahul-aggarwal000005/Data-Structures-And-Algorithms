#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&arr, int n) {
	int s = 0;
	int e = n - 1 ;

	while (s < e) {
		swap(arr[s], arr[e]);
		s++;
		e--;
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

	reverse(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}