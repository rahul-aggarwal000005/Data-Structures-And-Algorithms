#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int prime = 3;


bool rabinKarp(string text, string pattern) {

	int tLength = text.length();
	int pLength = pattern.length();

	if (tLength < pLength) return false;

	// hash for text
	ll t = 0;
	// hash for pattern
	ll p = 0;
	// h will be pow(prime,n-1)
	ll h = 1;
	// calculate the pattern hash and first window hash
	for (int i = 0; i < pLength; i++) {
		p = (p + pattern[i] * h) % mod;
		t = (t + text[i] * h) % mod;
		h = (h * prime) % mod;
	}
	h = h / prime;
	bool present = false;
	for (int i = 0; i <= tLength - pLength; i++) {
		if (p == t) {
			// check for the each character one by by
			bool flag = true;
			for (int j = 0; j < pLength; j++) {
				if (text[i + j] != pattern[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				present = true;
				cout << "Pattern is present at : " << i << endl;
			}
		}
		if (i < (tLength - pLength)) {
			// update the next window hash
			t -= text[i];
			t /= prime;
			t += text[i + pLength] * h;
		}
	}
	return present;

}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
		text : DATA STRUCTURES AND ALGORITHMS

		PATTERN : AND

	*/

	string text;
	getline(cin, text);
	string pattern;
	getline(cin, pattern);

	if (rabinKarp(text, pattern)) {
		cout << "Present";
	} else {
		cout << "Absent";
	}
	return 0;
}