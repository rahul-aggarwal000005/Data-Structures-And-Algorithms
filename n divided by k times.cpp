#include <bits/stdc++.h>
using namespace std;

class item {
public:
	int val;
	int count;
	item() {
		count = 0;
	}
};

void moreThanK(int a[], int n, int k) {

	item temp[k - 1];
	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < k - 1; j++) {
			if (temp[j].val == a[i]) {
				temp[j].count += 1;
			}
		}
		if (j == k - 1) {
			// if no such element already exist
			// check if there is any empty space
			int p;
			for (p = 0; p < k - 1; p++) {
				if (temp[p].count == 0) {
					temp[p].val = a[i];
					temp[p].count = 1;
					break;
				}
			}

			if (p == k - 1) {
				// if no empty space is there then we decrease the count
				for (p = 0; p < k - 1; p++) {
					temp[p].count -= 1;
				}
			}
		}
	}

	// temp will contan the possible candidates
	for (int i = 0; i < k - 1; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (temp[i].val == a[j]) cnt++;
		}

		if (cnt > n / k) cout << temp[i].val << endl;
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	moreThanK(a, n, k);

	return 0;
}