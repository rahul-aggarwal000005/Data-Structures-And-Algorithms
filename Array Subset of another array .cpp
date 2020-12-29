#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> &a, vector<int> &b) {
	int n = a.size();
	int m = b.size();

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]]++;
	}

	for (int i = 0; i < m; i++) {
		if (mp.find(b[i]) == mp.end()) return false;
		else {
			if (mp[b[i]] == 0) return false;
			mp[b[i]]--;
		}
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {

		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		if (isSubset(a, b)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}

	}

	return 0;
}