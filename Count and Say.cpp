#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
	if (n == 1) return "1";
	string recResult = countAndSay(n - 1);
	string ans = "";
	char ch = recResult[0];
	int count = 0;
	for (int i = 0; i < recResult.length(); i++) {
		if (ch == recResult[i]) {
			count++;
		} else {
			ans = ans + to_string(count);
			ans = ans + string(1, ch);
			ch = recResult[i];
			count = 1;
		}
	}
	ans = ans + to_string(count);
	ans = ans + string(1, ch);
	return ans;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	string ans = countAndSay(n);
	cout << ans << endl;
	return 0;
}