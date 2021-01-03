#include <bits/stdc++.h>
using namespace std;

int smallestWindow(string s) {
	unordered_set<char> d;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		d.insert(s[i]);
	}

	int distinct = d.size();
	char present[26] = {0};
	int cnt = 0;
	int l = 0;
	int r = 0;
	int len = n;
	while (r < n) {
		int ch = s[r] - 'a';
		if (present[ch] == 0) {
			cnt++;
		}
		present[ch]++;
		if (cnt == distinct) {
			len = min(r - l + 1, len);
			// move the left pointer till the cnt is not less than distinct
			while (l < n and present[s[l] - 'a'] > 1) {
				present[s[l] - 'a']--;
				l++;
			}
			present[s[l] - 'a']--;
			len = min(r - l + 1, len);
			l++;
			cnt--;
		}
		r++;
	}

	return len;
}

int main() {


#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int len = smallestWindow(s);
	cout << len << endl;
	return 0;
}