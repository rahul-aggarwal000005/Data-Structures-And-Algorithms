#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int lps(string s) {
	int n = s.length();
	int dp[n + 1] = {0};
	int i = 1;
	int len = 0;
	while (i < n) {
		if (s[i] == s[len]) {
			len++;
			dp[i] = len;
			i++;
		} else {
			if (len > 0) {
				len = dp[len - 1];
			} else {
				dp[i] = 0;
				i++;
			}
		}
	}
	return dp[n - 1];
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int ans = lps(s);
	cout << ans << endl;
	return 0;
}