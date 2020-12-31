#include<bits/stdc++.h>
using namespace std;



int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string keys[26] = {
		"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666",
		"7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"
	};

	string s;
	getline(cin, s);
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			ans = ans + "0";
		} else {
			ans = ans + keys[s[i] - 'A'];
		}
	}
	cout << ans << endl;
	return 0;
}