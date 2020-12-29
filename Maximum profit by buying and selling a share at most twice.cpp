#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {

	int n = prices.size();
	vector<int> profit(n, 0);

	// traverse the prices array to store the one transaction profit

	int minVal = prices[0];
	int p = 0;
	for (int i = 1; i < n; i++) {
		if (minVal < prices[i]) {
			p = prices[i] - minVal;
		} else {
			minVal = prices[i];
			p = 0;
		}
		profit[i] = max(profit[i - 1], p);
	}

	int maxVal = prices[n - 1];
	p = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (maxVal > prices[i]) {
			p = maxVal - prices[i];
		} else {
			p = 0;
			maxVal = prices[i];
		}
		profit[i] = max(profit[i + 1], profit[i] + p);
	}
	return profit[0];

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}

	int profit = maxProfit(prices);
	cout << profit << endl;

	return 0;
}