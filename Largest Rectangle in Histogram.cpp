#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
	stack<int> s;
	int i = 0;
	int n = heights.size();
	int maxArea = 0;
	while (i < n) {
		if (s.empty() or heights[s.top()] <= heights[i]) {
			s.push(i++);
		}
		else {
			// consider the top bar as minimum height bar
			int h = heights[s.top()];
			s.pop();
			int w;
			if (s.empty()) {
				w = i;
			} else {
				w = i - s.top() - 1;
			}
			maxArea = max(maxArea, h * w);
		}
	}

	while (!s.empty()) {
		int h = heights[s.top()];
		s.pop();
		int w;
		if (s.empty()) {
			w = i;
		} else {
			w = i - s.top() - 1;
		}
		maxArea = max(maxArea, h * w);
	}

	return maxArea;

}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> heights(n);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}

	int maxHistogram = largestRectangleArea(heights);
	cout << maxHistogram << endl;

	return 0;
}