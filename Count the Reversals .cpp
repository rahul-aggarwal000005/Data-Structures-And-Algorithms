#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int countReversals(string str) {

	if (str.length() & 1) return -1;

	stack<char> s;
	string final = "";
	int n = str.length();
	for (int i = 0; i < n; i++) {
		if (str[i] == '{') {
			s.push('{');
		} else {
			if (!s.empty()) {
				s.pop();
			} else {
				final.push_back('}');
			}
		}
	}

	while (!s.empty()) {
		final.push_back(s.top());
		s.pop();
	}

	int open = 0;
	int close = 0;
	for (int i = 0; i < final.length(); i++) {
		if (final[i] == '{') open++;
		else close++;
	}
	float o = open / 2.0;
	float c = close / 2.0;
	int ans = ceil(o) + ceil(c);
	return ans;
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
		int ans = countReversals(s);
		cout << ans << endl;
	}

	return 0;
}