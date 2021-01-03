#include <bits/stdc++.h>
using namespace std;

int countSquares(int n) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (i * i < n) {
			cnt++;
		}
	}
	return cnt;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int ans = countSquares(n);
	cout << ans << endl;
	return 0;
}