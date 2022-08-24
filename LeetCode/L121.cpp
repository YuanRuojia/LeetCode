#include "L121.h"

L121::L121()
{
	int n;
	vector<int> prices;

	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		prices.emplace_back(cin.get() - '0');
		cin.get();
	}

	cout << this->maxProfit(prices) << endl;
}

int L121::maxProfit(vector<int>& prices)
{
	int min = INT_MAX;
	int maxprofit = 0;
	for (int i = 0; i < prices.size(); i++) {
		min = prices[i] < min ? prices[i] : min;
		maxprofit = prices[i] - min > maxprofit ? prices[i] - min : maxprofit;
	}

	return maxprofit;
}
/*
6
7 1 5 3 6 4
*/
