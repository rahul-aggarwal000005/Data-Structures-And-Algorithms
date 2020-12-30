#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*
		mat[N][N] = {{ 1, 2, -1, -4, -20 },
	    { -8, -3, 4, 2, 1 },
	     { 3, 8, 6, 1, 3 },
	     { -4, -1, 1, 7, -6 },
	     { 0, -4, 10, -5, 1 }};
	*/
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int maxDiff = INT_MIN;

	vector<vector<int>> maxArr(n, vector <int>(n));

	maxArr[n - 1][n - 1] = arr[n - 1][n - 1];

	for (int i = n - 2; i >= 0; i--) {
		maxArr[n - 1][i] = max(arr[n - 1][i], maxArr[n - 1][i + 1]);
		maxArr[i][n - 1] = max(arr[i][n - 1], maxArr[i + 1][n - 1]);
	}


	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			if (maxArr[i + 1][j + 1] - arr[i][j] > maxDiff) {
				maxDiff = maxArr[i + 1][j + 1] - arr[i][j];
			}
			maxArr[i][j] = max(arr[i][j], max(maxArr[i + 1][j], maxArr[i][j + 1]));
		}
	}

	cout << maxDiff;

	return 0;
}