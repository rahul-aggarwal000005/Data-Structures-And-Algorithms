#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &matrix, int r, int c) {

	int minVal = INT_MAX;
	int maxVal = INT_MIN;
	for (int i = 0; i < r; i++) {
		minVal = min(minVal, matrix[i][0]);
		maxVal = max(maxVal, matrix[i][c - 1]);
	}

	int desired = (r * c + 1) / 2;
	while (minVal < maxVal) {
		int mid = (maxVal + minVal) / 2;
		int lessThan = 0;
		for (int i = 0; i < r; i++) {
			place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
		}
		if (place < desired) {
			min = mid + 1;
		}
		else {
			max = mid;
		}
	}

	return min;

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
	int ans = median(matrix, r, c);
	cout << ans << endl;
	return 0;
}