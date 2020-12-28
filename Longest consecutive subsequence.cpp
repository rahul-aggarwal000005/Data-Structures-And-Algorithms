#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(vector<int> &arr, int N) {

	unordered_map<int, int> mp;
	for (int i = 0; i < N; i++) {
		mp[arr[i]]++;
	}

	int lcs = 1;
	for (int i = 0; i < N; i++) {
		// check if the current element has the potential to be the last element of the subsequence
		// check if the arr[i] + 1 exist in the array
		int cur = arr[i];

		if (mp.find(cur + 1) == mp.end()) {
			int cnt = 1;
			int j = cur;
			while (mp.find(cur) != mp.end()) {
				cur--;
			}

			lcs = max(lcs, j - cur);
		}
	}

	return lcs;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	/*
		N = 7
		a[] = {2,6,1,9,4,5,3}
	*/

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int lcs = findLongestConseqSubseq(arr, n);
	cout << lcs << endl;
	return 0;
}
