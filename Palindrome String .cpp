#include<bits/stdc++.h>
using namespace std;

bool isPlaindrome(string s) {
	int i = 0;
	int j = s.length() - 1;
	while (i <= j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	if (isPlaindrome(s)) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}