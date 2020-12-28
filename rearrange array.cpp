#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr) {

	int n = arr.size();

	// first number should be negative
	int neg = 0;
	int pos = 0;
	int i = 0;
	while (i < n) {
		if (arr[i] < 0) {
			swap(arr[i], arr[neg]);
			neg++;
		}
		i++;
	}

	// at even position negative elements should be placed
	int pp = neg;
	i = 1;
	while (i <= neg and pp < n) {
		swap(arr[i], arr[pp]);
		pp++;
		i += 2;
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// {1, 2, 3, -4, -1, 4}
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	rearrange(arr);

	for (int i : arr) {
		cout << i << " ";
	}
	return 0;
}