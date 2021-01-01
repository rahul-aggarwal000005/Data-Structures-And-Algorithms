#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int countPS(string s) {
	int n = s.length();
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n - 1; i++) {
		dp[i][i + 1] = s[i - 1] == s[i] ? 3 : 2;
	}

	for (int k = 3; k <= n; k++) {
		for (int i = 1, j = k; j <= n and i <= n; i++, j++) {
			if (s[i - 1] == s[j - 1]) {
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
			}
		}
	}

	return dp[1][n];


}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int ans = countPS(s);
	cout << ans << endl;

	return 0;
}