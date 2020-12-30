#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s) {
	int i = 0;
	int j = s.size() - 1;
	while (i <= j) {
		swap(s[i], s[j]);
		i++;
		j--;
	}
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<char> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	reverseString(s);
	for (auto x : s) {
		cout << x << " ";
	}
	return 0;
}