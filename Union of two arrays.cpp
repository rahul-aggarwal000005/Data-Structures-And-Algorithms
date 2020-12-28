#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		mp[b[i]]++;
	}

	cout << mp.size();
	return 0;
}