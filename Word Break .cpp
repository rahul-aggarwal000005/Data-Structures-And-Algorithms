#include<bits/stdc++.h>
using namespace std;

bool isPresent(vector<string> &words, string s) {
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == s)return true;
	}
	return false;
}

bool wordBreak(vector<string> &words, string str) {

	if (str.length() == 0)return true;
	for (int i = 1; i <= str.length(); i++) {
		if (isPresent(words, str.substr(0, i)) and wordBreak(words, str.substr(i, str.length() - i))) {
			return true;
		}
	}
	return false;
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