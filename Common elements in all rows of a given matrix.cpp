#include <bits/stdc++.h>
using namespace std;

void commonElement(vector<vector<int>> &arr) {
	unordered_map<int, int> mp;
	for (int i = 0; i < m; i++) {
		mp[arr[0][i]] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[arr[i][j]] == i) {
				mp[arr[i][j]] = i + 1;
				if (i == m - 1) {
					cout << mp[i][j] << " ";
				}
			}

		}
	}
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	commonElement(arr);
	return 0;
}