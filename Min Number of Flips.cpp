#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int minFlips(string s) {

	int n = s.length();
	// if first even pos is 1 and odd pos is 0
	int i = 0;
	int ca = 0;
	while (i < n) {
		if (i & 1 and s[i] != '1') {
			ca++;
		}
		else if (i % 2 == 0 and s[i] != '0') {
			ca++;
		}
		i++;
	}

	int cb = 0;
	i = 0;
	while (i < n) {
		if (i & 1 and s[i] != '0') {
			cb++;
		}
		else if (i % 2 == 0 and s[i] != '1') {
			cb++;
		}
		i++;
	}
	return min(ca, cb);

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
		int ans = minFlips(s);
		cout << ans << endl;
	}
	return 0;
}