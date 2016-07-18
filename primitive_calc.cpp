/*
 * primitive_calc.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
int dp[10000];
vector<int> optimal_sequence2(int n) {
	int ans[n + 1];
	int sol[n + 1];
	fill(ans, ans + n + 1, (1 << 30) - 1);
	ans[1] = 0;
	for (int i = 1; i < n; ++i) {
		if (i * 3 <= n) {
			ans[i * 3] = ans[i] + 1;
			sol[i * 3] = i;
		}
		if (i * 2 <= n) {
			if (ans[i * 2] > ans[i] + 1) {
				sol[i * 2] = i;
			}
			ans[i * 2] = min(ans[i * 2], ans[i] + 1);

		}
		if (ans[i + 1] > ans[i] + 1) {
			sol[i+1] = i;
		}
		ans[i + 1] = min(ans[i] + 1, ans[i + 1]);
	}
	vector<int> seq;
	seq.push_back(n);
	while (n > 1) {
		n=sol[n];
		seq.push_back(n);
	}
	reverse(seq.begin(), seq.end());
	return seq;

}

int optimal_sequence(int n) {
	if (dp[n] != -1) {
		return dp[n];
	}
	int x1, x2, x3, x = (1 << 30) - 1;
	if (n % 3 == 0) {
		x1 = 1 + optimal_sequence(n / 3);
		x = x1;
	}
	if (n % 2 == 0) {
		x2 = 1 + optimal_sequence(n / 2);
		x = min(x, x2);
	}
	x3 = 1 + optimal_sequence(n - 1);
	x = min(x, x3);
	dp[n] = x;
	return dp[n];
}




