#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string S, string P) {

	int n = S.length(); // length of the string in which we need to find
	int m = P.length(); // length of the string which need to find in S
	if (m > n) return "-1";

	char hashPat[256] = {0};
	char hashStr[256] = {0};
	for (int i = 0; i < m; i++) {
		hashPat[P[i]]++;
	}

	int count = 0;
	int start_index = -1;
	int start = 0;
	int end = 0;
	int minLength = INT_MAX;
	while (end < n) {
		char ch = S[end];
		hashStr[ch]++;
		if (hashPat[ch] != 0 and hashStr[ch] <= hashPat[ch]) {
			count++;
		}

		if (count == m) {
			while (hashStr[S[start]] > hashPat[S[start]] or hashPat[S[start]] == 0) {
				hashStr[S[start]]--;
				start++;
			}
			int len = end - start + 1;
			if (len < minLength) {
				start_index = start;
				minLength = len;
			}
		}
		end++;
	}

	if (start_index == -1) {
		return "-1";
	}
	string ans = S.substr(start_index, minLength);
	return ans;
}


int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// {act,god,cat,dog,tac}
	string s, p;
	cin >> s >> p;
	string ans = smallestWindow(s, p);
	cout << ans << endl;

	return 0;
}