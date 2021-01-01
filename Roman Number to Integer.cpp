#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int romanToDecimal(string s) {
	int ans = 0;
	int n = s.length();
	for (int i = 0; i < n;) {
		if (s[i] == 'I') {
			if (i < n - 1 and s[i + 1] == 'V') {
				ans += 4;
				i += 2;
			}
			else if (i < n - 1 and s[i + 1] == 'X') {
				ans += 9;
				i += 2;
			}
			else {
				ans += 1;
				i += 1;
			}
		}
		else if (s[i] == 'V') {
			ans += 5;
			i += 1;
		}
		else if (s[i] == 'X') {
			if (i < n - 1 and s[i + 1] == 'L') {
				ans += 40;
				i += 2;
			}
			else if (i < n - 1 and s[i + 1] == 'C') {
				ans += 90;
				i += 2;
			}
			else {
				ans += 10;
				i += 1;
			}
		}
		else if (s[i] == 'L') {
			ans += 50;
			i += 1;
		}
		else if (s[i] == 'C') {
			if (i < n - 1 and s[i + 1] == 'D') {
				ans += 400;
				i += 2;
			}
			else if (i < n - 1 and s[i + 1] == 'M') {
				ans += 900;
				i += 2;
			}
			else {
				ans += 100;
				i += 1;
			}
		}
		else if (s[i] == 'D') {
			ans += 500;
			i += 1;
		}
		else {
			ans += 1000;
			i += 1;
		}
	}
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int ans = romanToDecimal(s);
	cout << ans << endl;
	return 0;
}