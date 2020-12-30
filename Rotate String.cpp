#include<bits/stdc++.h>
using namespace std;

bool rotateString(string A, string B) {

	if (A.length() != B.length()) return false;
	if (A.length() == 0) return true;
	string c = A + A;
	int n = B.length();
	for (int i = 0; i < A.length(); i++) {
		string sub = c.substr(i, n);
		if (sub == B) return true;
	}
	return false;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	if (rotateString(a, b)) {
		cout << "true";
	} else {
		cout << "false";
	}

	return 0;
}