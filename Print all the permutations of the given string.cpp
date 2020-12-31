#include<bits/stdc++.h>
using namespace std;

void printPermutation(string a, string ans, set<string> &s) {

	if (a.length() == 0) {
		s.insert(ans);
		return;
	}
	for (int i = 0; i < a.length(); i++) {
		// without swap
		swap(a[0], a[i]);
		printPermutation(a.substr(1), ans + a[0], s);
		swap(a[0], a[i]);
	}
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		set<string> s;
		printPermutation(a, "", s);
		for (auto x : s) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}