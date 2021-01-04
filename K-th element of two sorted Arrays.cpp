#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int kthelement(vector<int> &a, vector<int> &b, int k) {
	int n = a.size();
	int m = b.size();
	vector<int> result;
	int i = 0;
	int j = 0;
	while (i < n and j < m) {
		if (a[i] < b[j]) {
			result.push_back(a[i]);
			i++;
		}
		else {
			result.push_back(b[j]);
			j++;
		}
	}
	while (i < n) {
		result.push_back(a[i]);
		i++;
	}
	while (j < m) {
		result.push_back(b[j]);
		j++;
	}

	return result[k - 1];



}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n);
		vector<int> b(m);;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		int ans = kthelement(a, b, k);
		cout << ans << endl;

	}
}