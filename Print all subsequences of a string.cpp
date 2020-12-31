#include<bits/stdc++.h>
using namespace std;

void printSubsequence(string a) {
	int n = a.length();
	int Limit = (1 << n);
	for (int val = 0; val < Limit; val++) {
		string ss = "";
		// val = 0 1 1

		for (int i = 0; i < n; i++) {
			int mask = (1 << i);

			if ((val & mask)) {
				ss = string(1, a[n - 1 - i]) + ss;
			} else {
				ss = "" + ss;
			}
		}
		cout << ss << endl;
	}
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a;
	cin >> a;
	printSubsequence(a);
	return 0;
}