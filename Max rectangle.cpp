#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int histogram(int heights[MAX], int n) {

	stack<int> s;
	int i = 0;
	int maxArea = 0;
	while (i < n) {
		if (s.empty() or heights[s.top()] <= heights[i]) {
			s.push(i++);
		} else {

			int h = heights[s.top()];
			s.pop();
			int w = s.empty() ? i : (i - s.top() - 1);
			maxArea = max(h * w, maxArea);
		}
	}

	while (!s.empty()) {
		int h = heights[s.top()];
		s.pop();
		int w = s.empty() ? i : (i - s.top() - 1);
		maxArea = max(h * w, maxArea);
	}
	return maxArea;

}

int maxArea(int M[][MAX], int n, int m) {

	// find the maximum reactangle area in the first row
	int area = histogram(M[0], m);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j] == 1) {
				M[i][j] += M[i - 1][j];
			}
		}
		area = max(area, histogram(M[i], m));
	}

	return area;

}


int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int M[MAX][MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
		}
	}

	int maxRectange = maxArea(M, n, n);
	cout << maxRectange << endl;
	return 0;
}