#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {

	int i = 0;
	int j = 0;
	int k = 0;
	int last = INT_MIN;
	vector<int> res;
	while (i < n1 and j < n2 and k < n3) {
		if (A[i] == B[j] and B[j] == C[k] and A[i] != last) {
			res.push_back(A[i]);
			last = A[i];
			i++;
			j++;
			k++;
		}
		else if (min({A[i], B[j], C[k]}) == A[i]) i++;
		else if (min({A[i], B[j], C[k]}) == B[j]) j++;
		else k++;
	}

	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*

		n1 = 6; A = {1, 5, 10, 20, 40, 80}
		n2 = 5; B = {6, 7, 20, 80, 100}
		n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
	*/
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int a[n1];
	int b[n2];
	int c[n3];

	for (int i = 0; i < n1; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n2; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n3; i++) {
		cin >> c[i];
	}

	vector<int> res = commonElements(a, b, c, n1, n2, n3);
	for (auto x : res) {
		cout << x << " ";
	}


	return 0;
}
