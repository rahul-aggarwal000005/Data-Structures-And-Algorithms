#include <bits/stdc++.h>
using namespace std;

bool wildcardMatching(string w, string s) {
	int n = w.length();
	int m = s.length();
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		if (w[i - 1] == '*' or w[i - 1] == '?') dp[i][0] = true;
		else break;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (w[i - 1] == '*') {
				if (dp[i - 1][j]) {
					dp[i][j] = true;
				}
				else if (dp[i - 1][j - 1]) {
					dp[i][j] = true;
				}
				else if (dp[i][j - 1]) {
					dp[i][j] = true;
				}
			}
			else if (w[i - 1] == '?' or w[i - 1] == s[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = false;
			}
		}
	}
	return dp[n][m];
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// {act,god,cat,dog,tac}
	int t;
	cin >> t;
	while (t--) {

		string w, s;
		cin >> w >> s;
		if (wildcardMatching(w, s)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}