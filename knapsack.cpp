/*
 * knapsack.cpp
 *
 *  Created on: Jul 11, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
struct item {
	int value;
	int weight;
};
bool cmp3(struct item a, struct item b) {
	double r1 = (double) a.value / a.weight;
	double r2 = (double) b.value / b.weight;
	return r1 > r2;
}
double fraction_knapsack(int cap, item a[], int n) {
	sort(a, a + n, cmp3);
	double x = 0;
	int i = 0;
	double w, v;
	while (cap > 0) {
		w = min(cap, a[i].weight);
		v = w * a[i].value / a[i].weight;
		x += v;
		cap -= w;
		i++;
	}
	return x;

}
int optimal_weight(int W, const vector<int> &w) {
	//write your code here
	vector<vector<int> > dp(w.size() + 1, vector<int>(W + 1,0));
	for (int i = 1; i <= w.size(); ++i) {
		for (int j = 1; j <= W; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (j >= w[i - 1]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + w[i - 1]);
			}
		}
	}
	return dp[w.size()][W];
}



