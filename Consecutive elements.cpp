#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
	int n = s.length();
	string ans = "";
	ans = s[0];
	int j = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == ans[j]) continue;
		else {
			ans = ans + s[i];
			j++;
		}
	}
	return ans;
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

		string s;
		cin >> s;
		string ans = removeDuplicates(s);
		cout << ans << endl;
	}
	return 0;
}