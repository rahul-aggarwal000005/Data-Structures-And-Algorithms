#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool canObtain(int arr[], int n, int m, int blade) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > blade) {
			sum += arr[i] - blade;
		}
	}
	return sum >= m;
}

int findheight(int heights[], int n, int m) {
	int s = 0;
	int e = 0;
	for (int i = 0; i < n; i++) {
		e = max(heights[i], e);
	}
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (canObtain(heights, n, m, mid)) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int m;
	cin >> m;
	int heights[n];
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}

	int ans = findheight(heights, n, m);
	cout << ans << endl;
}