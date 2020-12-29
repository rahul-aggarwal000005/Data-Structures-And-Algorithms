#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> &matrix, int r, int c) {
	int sr = 0;
	int er = r - 1;
	int sc = 0;
	int ec = c - 1;
	vector<int> res;
	while (sr <= er and sc <= ec) {

		// left to right
		if (sr <= er) {
			if (sr <= er) {
				for (int i = sc; i <= ec; i++) {
					res.push_back(matrix[sr][i]);
				}
				sr++;
			}
		}
		//top to down
		if (sc <= ec) {
			for (int i = sr; i <= er; i++) {
				res.push_back(matrix[i][ec]);
			}
			ec--;
		}
		// right to left
		if (sr <= er) {
			for (int i = ec; i >= sc; i--) {
				res.push_back(matrix[er][i]);
			}
			er--;
		}
		// botton to top
		if (sc <= ec) {
			for (int i = er; i >= sr; i--) {
				res.push_back(matrix[i][sc]);
			}
			sc++;
		}
	}

	return res;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int r, c;
	cin >> r >> c;
	vector<vector<int>> matrix(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<int> res = spiralPrint(matrix, r, c);
	for (auto x : res) {
		cout << x << " ";
	}
	return 0;
}