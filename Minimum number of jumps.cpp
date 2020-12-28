#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr, int n) {
	if (n <= 1) return 0;

	if (arr[0] == 0) return -1;

	int jumps = 1;
	int maxReach = arr[0];
	int steps = arr[0];

	for (int i = 1; i < n; i++) {
		if (i == n - 1) return jumps;
		maxReach = max(maxReach, arr[i] + i);
		steps--;
		if (steps == 0) {
			jumps++;
			if (maxReach <= i) return -1;
			steps = maxReach - i;
		}
	}

	return jumps;


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

	int ans = minJumps(arr, n);
	cout << ans << endl;
	return 0;
}