#include <bits/stdc++.h>
using namespace std;

int minSwap(string s) {
	vector<int> open;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] == '[') open.push_back(i);
	}
	int sum = 0;
	int count = 0;
	int o = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '[') {
			o++;
			count++;
		}
		else {
			count--;
		}
		if (count < 0) {
			sum += open[o] - i;
			swap(s[open[o]], s[i]);
			o++;
			count = 1;
		}
	}

	return sum;
}

int main() {


#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int count = minSwap(s);
		cout << count << endl;
	}
	return 0;
}