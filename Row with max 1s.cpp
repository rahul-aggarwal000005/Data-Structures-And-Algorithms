#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr, int n, int m) {

	int i = 0;
	int j = m - 1;
	int ans = -1;
	while (i<n and j >= 0) {
		if (arr[i][j] == 0) {
			i++;
		}
		else {
			j--;
			ans = i;
		}
	}
	return ans;
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
	int ans = rowWithMax1s(matrix, r, c);
	cout << ans << endl;
	return 0;
}