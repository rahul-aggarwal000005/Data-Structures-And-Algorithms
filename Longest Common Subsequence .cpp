#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2) {

	int dp[x + 1][y + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}

	return dp[x][y];

}

int main() {


#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x, y;
	cin >> x >> y;
	string s1, s2;
	cin >> s1 >> s2;
	int ans = lcs(x, y, s1, s2);
	cout << ans << endl;
	return 0;
}