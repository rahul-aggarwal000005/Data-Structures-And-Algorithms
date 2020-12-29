#include <bits/stdc++.h>
using namespace std;

class item {
public:
	int val;
	int row;
	int col;
	item(int v, int r, int c) {
		val = v;
		col = c;
		row = r;
	}
};

class compare {
public:
	bool operator()(item const &a, item const &b) {
		return a.val > b.val;
	}
};

int kthSmallest(vector<vector<int>> &arr, int n, int k) {

	priority_queue<item, vector<item>, compare> pq;
	for (int i = 0; i < n; i++) {
		pq.push(item(arr[i][0], i, 0));
	}

	int count = 0;
	while (!pq.empty()) {
		item x = pq.top();
		pq.pop();
		count++;
		if (count == k) {
			return x.val;
		}

		int c = x.col;
		int r = x.row;
		if (c + 1 < n) {
			pq.push({arr[r][c + 1], r, c + 1});
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = kthSmallest(arr, n, k);
	cout << ans << endl;
	return 0;
}