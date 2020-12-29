#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k =  3;
	int arr[] = {2, 1, 5, 6, 3};
	int n = 5;
	int good = 0;
	int bad = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= k) ++good;
	}

	for (int i = 0; i < good; i++) {
		if (arr[i] > k) ++bad;
	}
	int ans = bad;
	for (int i = 0, j = good; j < n; ++j, ++i) {
		if (arr[i] > k) --bad;
		if (arr[j] > k)++bad;
		ans = min(ans, bad);
	}

	cout << ans << endl;

	return 0;
}