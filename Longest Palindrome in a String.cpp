#include<bits/stdc++.h>
using namespace std;

string lps(string s) {
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
		}
	}

	for (int g = 0; g < n - 2; g++) {
		for (int i = 0, j = g + 2; i < n and j < n; i++, j++) {
			if (dp[i + 1][j - 1] and s[i] == s[j]) {
				dp[i][j] = true;
			}
		}
	}

	int length = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == true) {

				if (length < (j - i + 1)) {
					length = j - i + 1;
					start = i;
				}
			}
		}
	}
	string ans = s.substr(start, length);
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string ans = lps(s);
		cout << ans << endl;
	}
	return 0;
}