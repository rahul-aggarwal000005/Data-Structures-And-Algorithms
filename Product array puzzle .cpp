#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> productExceptSelf(vector<ll> &nums, int n) {
	vector<ll> product(n, 1);
	ll temp = 1;
	for (int i = 0; i < n; i++) {
		product[i] = temp;
		temp = temp * nums[i];
	}
	temp = 1;
	for (int i = n - 1; i >= 0; i--) {
		product[i] = product[i] * temp;
		temp = temp * nums[i];
	}
	return product;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*
		6
		{0,0,5,5,0,0}
	*/
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> ans = productExceptSelf(arr, n);
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}