#include <bits/stdc++.h>
using namespace std;

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

	// [1,3,4,2,2]

	// slow fast pointer approach
	int slow = arr[0];
	int fast = arr[0];

	do {
		fast = arr[arr[fast]];
		slow = arr[slow];
	} while (slow != fast);

	fast = arr[0];
	while (fast != slow) {
		fast = arr[fast];
		slow = arr[slow];
	}
	cout << fast << " ";
	return 0;
}