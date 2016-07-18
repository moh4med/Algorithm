/*
 * lcs.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
int lcs2(vector<int> &a, vector<int> &b) {
	//write your code here
	int n = a.size();
	int m = b.size();
	vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			}
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	return dp[n][m];
}
int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
//write your code here
	int n = a.size();
	int m = b.size();
	int l = c.size();
	vector<vector<vector<int> > > dp(n + 1,
			vector<vector<int> >(m + 1, vector<int>(l + 1, 0)));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= l; ++k) {
				dp[i][j][k] = max(dp[i - 1][j][k],
						max(dp[i][j - 1][k], dp[i][j][k - 1]));
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
					dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - 1][k-1]);
				}
			}
		}
	}

	return dp[n][m][l];
}




