#include <bits/stdc++.h>
using namespace std;

#define ll long long
int *findTwoElement(int *A, int n) {

	long long len = n;
	long long int Sum_N = (len * (len + 1) ) / 2, Sum_NSq = (len * (len + 1) * (2 * len + 1) ) / 6;
	long long int missingNumber = 0, repeating = 0;

	for (int i = 0; i < n; i++) {
		Sum_N -= (long long int)A[i];
		Sum_NSq -= (long long int)A[i] * (long long int)A[i];
	}

	missingNumber = (Sum_N + Sum_NSq / Sum_N) / 2;
	repeating = missingNumber - Sum_N;
	int *ans = new int[2];
	ans[0] = repeating;
	ans[1] = missingNumber;
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int *ans = findTwoElement(arr, n);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}