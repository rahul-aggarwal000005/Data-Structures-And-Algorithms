#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string longestCommonPrefix(vector<string> &strs) {
	int n = strs.size();
	if (n == 0) return "";

	string result = "";
	string first = strs[0];
	for (int i = 0; i < first.length(); i++) {
		// extract the first charater of the first string
		char ch = first[i];
		for (int j = 0; j < n; j++) {
			string x = strs[j];
			if (i >= x.length() or ch != x[i]) return result;
		}
		result += ch;
	}
	return result;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
	}
	string result = longestCommonPrefix(strs);
	cout << result << endl;
	return 0;
}