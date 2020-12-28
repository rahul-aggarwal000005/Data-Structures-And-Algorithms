#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
	sort(intervals.begin(), intervals.end());

	int start = intervals[0][0];
	int end = intervals[0][1];
	int n = intervals.size();

	vector<vector<int>> res;
	for (int i = 1; i < n; i++) {
		if (intervals[i][0] <= end) {
			end = max(intervals[i][1], end);
		}
		else {
			vector<int> v(2);
			v[0] = start;
			v[1] = end;
			res.push_back(v);
			start = intervals[i][0];
			end = intervals[i][1];
		}
	}
	vector<int> v(2);
	v[0] = start;
	v[1] = end;
	res.push_back(v);

	return res;
}


int main() {

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// [[1,3],[2,6],[8,10],[15,18]]
	int n;
	cin >> n;
	vector<vector<int>> intervals(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		intervals[i][0] = s;
		intervals[i][1] = e;
	}
	vector<vector<int>> res = merge(intervals);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << " " << res[i][1] << endl;
	}

	return 0;
}