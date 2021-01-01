#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define R 200
#define C 200

int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool findWord(char matrix[][C], string word, int n, int m, int i, int j) {
	// check if the first character matches
	if (word[0] != matrix[i][j]) return false;

	for (int dir = 0; dir < 8; dir++) {
		int r = i + x[dir];
		int c = j + y[dir];
		bool f = true;
		for (int i = 1; i < word.length(); i++) {
			if (r < 0 or r >= n or c <0  or c >= m or word[i] != matrix[r][c]) {
				f = false;
				break;
			}
			r = r + x[dir];
			c = c + y[dir];
		}
		if (f) return true;
	}
	return false;
}

void wordSearch(char matrix[][C], string word, int n, int m) {
	bool found = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (findWord(matrix, word, n, m, i, j)) {
				found = true;
				cout << i << " " << j << ", ";
			}
		}
	}
	if (!found) {
		cout << "-1";
	}
	cout << endl;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		char matrix[R][C];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> matrix[i][j];
			}
		}
		string word;
		cin >> word;
		wordSearch(matrix, word, n, m);
	}
	return 0;
}