#include <bits/stdc++.h>
using namespace std;

int minChars(string s) {
	string temp;
	temp = s + '#';
	reverse(s.begin(), s.end());
	temp = temp + s;
	int n = temp.length();
	int lps[n + 1] = {0};
	int i = 1;
	int len = 0;
	while (i < n) {
		if (temp[i] == temp[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len > 0) len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
	n = s.length();
	return n - lps[temp.length() - 1];
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int ans = minChars(s);
	cout << ans << endl;
	return 0;
}