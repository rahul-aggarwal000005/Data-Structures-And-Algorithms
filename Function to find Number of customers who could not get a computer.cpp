#include <bits/stdc++.h>
using namespace std;

bool runCustomerSimulation(int n, string s) {
	char dp[256] = {0};
	int cur = 0;
	int maxPc = 0;
	for (int i = 0; i < s.length(); i++) {
		if (dp[s[i]] == 0) {
			cur++;
			dp[s[i]]++;
		}
		else {
			cur--;
		}
		maxPc = max(maxPc, cur);
	}

	return maxPc <= n;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// {act,god,cat,dog,tac}
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (runCustomerSimulation(n, s)) {
		cout << "0";
	} else {
		cout << "1";
	}
	return 0;
}