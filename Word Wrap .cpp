#include<bits/stdc++.h>
using namespace std;

int printPath(int path[], int n) {
	int k;
	if (path[n] == 1) {
		k = 1;
	}
	else {
		k = printPath(path, path[n] - 1) + 1;
	}
	cout << path[n] << " " << n << " ";
	return k;
}

void wordWrap(int arr[], int n, int m) {
	int space[n + 1][n + 1];
	for (int i = 1; i <= n; i++) {
		space[i][i] = m - arr[i - 1];
		for (int j = i + 1; j <= n; j++) {
			space[i][j] = space[i][j - 1] - arr[j - 1] - 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (space[i][j] < 0) {
				space[i][j] = INT_MAX;
			}
			else if (j == n and space[i][j] >= 0) {
				space[i][j] = 0;
			}
			else {
				space[i][j] = space[i][j] * space[i][j];
			}
		}
	}

	int cost[n + 1] = {0};
	int path[n + 1] = {0};
	for (int j = 1; j <= n; j++) {
		cost[j] = INT_MAX;
		for (int i = 1; i <= j; i++) {
			if (cost[i - 1] != INT_MAX and space[i][j] != INT_MAX and (cost[i - 1] + space[i][j] < cost[j])) {
				cost[j] = cost[i - 1] + space[i][j];
				path[j] = i;
			}
		}
	}

	printPath(path, n);
}


int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int m;
		cin >> m;
		wordWrap(arr, n, m);
		cout << endl;
	}
	return 0;
}