#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void constructLps(vector<int> &lps, string s) {
	int i = 1;
	int len = 0;
	int n = s.length();
	while (i < n) {
		if (s[i] == s[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len > 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}

}

bool KMPAlgo(string text, string pattern) {
	int tLength = text.length();
	int pLength = pattern.length();
	if (tLength < pLength) return false;

	string temp = pattern;
	temp = temp + '#';
	temp = temp + text;
	vector<int> lps(temp.length() + 1, 0);
	constructLps(lps, temp);
	bool Present = false;
	for (int i = pLength; i < temp.length(); i++) {
		if (lps[i] == pLength) {
			Present = true;
			cout << "Present at : " << (i - 2 * pLength) << endl;
		}
	}
	return Present;

}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string text;
	getline(cin, text);
	string pattern;
	getline(cin, pattern);

	if (KMPAlgo(text, pattern)) {
		cout << "Present";
	} else {
		cout << "Absent";
	}
	return 0;
}