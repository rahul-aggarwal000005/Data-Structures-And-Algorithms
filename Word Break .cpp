#include<bits/stdc++.h>
using namespace std;

bool isPresent(vector<string> &words, string s) {
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == s)return true;
	}
	return false;
}

bool solve(vector<string> &words, string str, unordered_map<string, int> &dp) {
	int n = str.length();
	if (n == 0) {
		return true;
	}

	if (dp[str]) return true;

	for (int i = 1; i <= n; i++) {
		if (isPresent(words, str.substr(0, i)) and solve(words, str.substr(i, n - i), dp)) {
			dp[str] = 1;
			return dp[str];
		}
	}
	dp[str] = 0;
	return false;
}

bool wordBreak(vector<string> &words, string str) {

	unordered_map<string, int> dp;
	return solve(words, str, dp);
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
			n = 12
			B = { "i", "like", "sam", "sung", "samsung", "mobile",
			"ice","cream", "icecream", "man", "go", "mango" }
	*/
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	string str;
	cin >> str;
	if (wordBreak(words, str)) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}