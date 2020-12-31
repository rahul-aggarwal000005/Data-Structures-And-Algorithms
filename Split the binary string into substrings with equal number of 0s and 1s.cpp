#include<bits/stdc++.h>
using namespace std;

int countWays(string s) {
	int count = 0;
	int count1 = 0;

	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') count++;
		if (s[i] == '1') count1++;
		if (count == count1) cnt++;
	}

	if (count1 != count) return -1;

	return cnt;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int ans = countWays(s);
	cout << ans << endl;
	return 0;
}