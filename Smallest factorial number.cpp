#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool contains(int n, int x) {
	// check n contains x trailing zeroes
	int count = 0;
	for (int div = 5; n / div >= 1; div *= 5) {
		count += (n / div);
	}
	return count >= x;
}

int findNum(int n) {
	int s = 1;
	int e = 5 * n;
	int ans = 5 * n;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (contains(mid, n)) {
			ans = mid;
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
	int ans = findNum(n);
	cout << ans << endl;
}