#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2) {
	int n = str1.length();
	int m = str2.length();
	if (n != m) return false;

	unordered_map<char, char> s1;
	unordered_set<char> s2;
	for (int i = 0; i < n; i++) {
		// check if the current character is already mapped or not
		char ch1 = str1[i];
		char ch2 = str2[i];
		if (s1.find(ch1) == s1.end()) {
			if (s2.find(ch2) == s2.end()) {
				s1[ch1] = ch2;
				s2.insert(ch2);

			} else {

				return false;
			}
		}
		else {
			if (s1[ch1] != ch2) {
				return false;
			}
		}
	}

	return true;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// {act,god,cat,dog,tac}
	string a, b;
	cin >> a >> b;
	bool ans = areIsomorphic(a, b);
	cout << ans << endl;
	return 0;
}