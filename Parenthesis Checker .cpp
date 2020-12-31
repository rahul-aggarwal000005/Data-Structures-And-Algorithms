#include<bits/stdc++.h>
using namespace std;

bool ispar(string a) {

	stack<char> s;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(' or a[i] == '{' or a[i] == '[') {
			s.push(a[i]);
		}
		else {
			if (s.empty()) return false;
			else if (a[i] == ')' and s.top() == '(') s.pop();
			else if (a[i] == '}' and s.top() == '{') s.pop();
			else if (a[i] == ']' and s.top() == '[') s.pop();
			else return false;
		}
	}
	return s.empty();
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	if (ispar(s)) {
		cout << "true" << endl;
	}
	else {
		cout << "false";
	}
	return 0;
}