#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string secFrequent(string arr[], int n) {
	unordered_map<string, int> mp;
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}

	int max1 = 0, max2 = 0;
	for (auto x : mp) {
		if (x.second > max1) {
			max2 = max1;
			max1 = x.second;
		}
		else if (x.second > max2) {
			max2 = x.second;
		}
	}
	string result = "";
	for (auto x : mp) {
		if (x.second == max2) {
			result = x.first;
			break;
		}
	}
	return result;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	string arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	string ans = secFrequent(arr, n);
	cout << ans << endl;
	return 0;
}