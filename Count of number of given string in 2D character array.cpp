#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int findWord(string input[], string word, int i, int j, int n, int m, int idx) {
	if (idx == word.length()) return true;
	if (i >= 0 and i<n and j >= 0 and j < m and word[idx] == input[i][j]) {
		char ch = word[0];
		input[i][j] = '0';
		if (findWord(input, word, i + 1, j, n, m, idx + 1)) return true;
		if (findWord(input, word, i, j + 1, n, m, idx + 1)) return true;
		if (findWord(input, word, i - 1, j, n, m, idx + 1)) return true;
		if (findWord(input, word, i, j - 1, n, m, idx + 1)) return true;
		input[i][j] = ch;
	}
	return false;
}

int count(string input[], string word) {
	int n = 6;
	int m = input[0].size();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (findWord(input, word, i, j, n, m, 0)) {
				ans++;
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

	string input[] = {
		"BBABBM",
		"CBMBBA",
		"IBABBG",
		"GOZBBI",
		"ABBBBC",
		"MCIGAM"
	};

	string word;
	cin >> word;
	int ans = count(input, word);
	cout << ans << endl;
	return 0;
}