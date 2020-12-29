#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
	int n = matrix.size();
	int m = matrix[0].size();

	int i = 0;
	int j = m - 1;
	while (i<n and j >= 0) {
		if (matrix[i][j] == target) return true;
		if (matrix[i][j] > target) j--;
		else i++;
	}
	return false;
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
	int target;
	cin >> target;
	if (searchMatrix(matrix, target)) {
		cout << "true";
	} else {
		cout << "false";
	}
	return 0;
}