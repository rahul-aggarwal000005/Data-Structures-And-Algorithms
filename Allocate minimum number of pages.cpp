#include<bits/stdc++.h>
#define ll long long int
using namespace std;


bool canRead(int arr[], int n, int m, int maxPages) {
	int s = 1;
	int pages = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > maxPages) return false;
		if (pages + arr[i] <= maxPages) {
			pages += arr[i];
		}
		else {
			pages = arr[i];
			s++;
			if (s > m) return false;
		}

	}
	return true;
}
int findPages(int *arr, int n, int m) {
	//code here
	if (m > n) return -1;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	ll s = 0;
	ll e = sum;
	ll ans = INT_MAX;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (canRead(arr, n, m, mid)) {
			ans = min(mid, ans);
			e = mid - 1;
		}
		else {
			s = mid + 1;
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
	int pages[n];
	for (int i = 0; i < n; i++) {
		cin >> pages[i];
	}
	int m;
	cin >> m;
	int ans = findPages(pages, n, m);
	cout << ans << endl;
}