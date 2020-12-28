#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
	int minPrice = INT_MAX;
	int maxprofit = 0;
	int n = prices.size();
	for (int i = 0; i < n; i++) {
		if (prices[i] < minPrice) {
			minPrice = prices[i];
		}
		else if (prices[i] - minPrice > maxprofit) {
			maxprofit = prices[i] - minPrice;
		}
	}

	return maxprofit;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
// 7,1,5,3,6,4
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