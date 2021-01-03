#include <bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C) {
	if (A > B) {
		if (B > C) return B;
		else if (A > C) return C;
		else return A;
	}
	else {
		if (C < A) return A;
		else if (C > B) return B;
		else return C;
	}
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b, c;
	cin >> a >> b >> c;
	int ans = middle(a, b, c);
	cout << ans << endl;
	return 0;
}