#include<bits/stdc++.h>
using namespace std;

void duplicates(string s) {

	char characters[26] = {0};
	for (int i = 0; i < s.length(); i++) {
		characters[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (characters[i] > 1) {
			char ch = (char)('a' + i);
			cout << ch << endl;
		}
	}
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	duplicates(s);

	return 0;
}