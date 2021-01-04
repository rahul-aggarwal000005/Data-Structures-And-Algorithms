#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool inSequence(int a, int b, int c) {
	int diff = (b - a);
	if (diff == 0) {
		return 1;
	}
	if (diff < 0) {
		if (c >= 0) {
			return 0;
		}
		else if (diff % c == 0) return 1;
		return 0;
	}
	else {
		if (c <= 0) return 0;
		else if (diff % c == 0) return 1;
		return 0;
	}
	return 0;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b, c;
	cin >> a >> b >> c;
	if (inSequence(a, b, c)) {
		cout << "1";
	} else {
		cout << "0";
	}
}