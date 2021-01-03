#include <bits/stdc++.h>
using namespace std;

int calculate(string a, string b) {
	int n = a.length();
	int m = b.length();
	int count[256] = {0};
	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}
	for (int i = 0; i < m; i++) {
		count[b[i]]--;
	}
	for (int i = 0; i < 256; i++) {
		if (count[i]) return -1;
	}

	int i = n - 1;
	int j = m - 1;
	int res = 0;
	while (i >= 0 and j >= 0) {
		if (a[i] == b[j]) {
			i--;
			j--;
		}
		else {
			res++;
			j--;
		}
	}
	return res;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// {act,god,cat,dog,tac}
	string a, b;
	cin >> a >> b;
	int ans = calculate(a, b);
	cout << ans << endl;
	return 0;
}