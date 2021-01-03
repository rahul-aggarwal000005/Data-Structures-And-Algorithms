#include <bits/stdc++.h>
using namespace std;

bool valid(string s) {
	if (s.length() > 3) return false;
	if (s.length() > 1) {
		if (s[0] == '0') return false;
	}
	if (stoi(s) > 255) return false;
	return true;
}


vector<string> restoreIpAddresses(string s) {
	int n = s.length();
	vector<string> ans;
	if (n <= 3) return ans;
	for (int i = 1; i <= 3 and i < s.length(); i++) {
		string firstPart = s.substr(0, i);
		string remainingFirst = s.substr(i);
		if (valid(firstPart)) {
			for (int j = 1; j <= 3 and j < remainingFirst.length(); j++) {
				string secondPart = remainingFirst.substr(0, j);
				string remainingSecond = remainingFirst.substr(j);
				if (valid(secondPart)) {
					for (int k = 1; k <= 3 and k < remainingSecond.length(); k++) {
						string thirPart = remainingSecond.substr(0, k);
						string fourthPart = remainingSecond.substr(k);
						if (valid(thirPart) and valid(fourthPart)) {
							string res = firstPart + "." + secondPart + "." + thirPart + "." + fourthPart;
							ans.push_back(res);
						}
					}
				}
			}
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
	vector<string> ans = restoreIpAddresses(s);
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}