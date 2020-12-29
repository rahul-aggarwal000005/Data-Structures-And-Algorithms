#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = i; j < m; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for (int i = 0; i < n; i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
}

int main(int argc, char const *argv[])
{
#ifndef Rahul_Compiler
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	rotate(matrix);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}