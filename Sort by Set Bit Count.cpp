#include <bits/stdc++.h>
using namespace std;

#define ll long long


bool comp(int x, int y) {
	int bitsx = __builtin_popcount(x);
	int bitsy = __builtin_popcount(y);
	if (bitsx <= bitsy) return false;
	return true;
}

void sortBySetBitCount(int arr[], int n) {
	stable_sort(arr, arr + n, comp);
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*
		9
		{5, 2, 3, 9, 4, 6, 7, 15, 32}
	*/
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sortBySetBitCount(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}