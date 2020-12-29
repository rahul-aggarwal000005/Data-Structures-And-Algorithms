#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
#ifndef Rahul_Compiler
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n * n; i++) {
			int x;
			cin >> x;
			pq.push(x);
		}
		while (!pq.empty()) {
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
	return 0;
}