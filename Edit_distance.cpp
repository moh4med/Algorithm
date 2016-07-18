/*
 * Edit_distance.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
void output_allignment(vector<vector<int> > dp, string a, string b, int n,
		int m) {
	if (n == 0 && m == 0) {
		return;
	}
	if (m > 0 && dp[m][n] == dp[m - 1][n] + 1) {
		output_allignment(dp, a, b, n, m - 1);
		cout<<"- "<<b[m-1]<<endl;
	} else if (n > 0 && dp[m][n] == dp[m][n - 1] + 1) {
		output_allignment(dp, a, b, n - 1, m);
		cout<<a[n-1]<<" -\n";
	} else {
		output_allignment(dp, a, b, n - 1, m - 1);
		cout<<a[n-1]<<" "<<b[m-1]<<endl;
	}
}
int edit_distance(const string &str1, const string &str2) {
	//write your code here
	int n = str1.size();
	int m = str2.size();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; ++i) {
		dp[0][i] = i;
	}
	for (int i = 0; i <= m; ++i) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= m; ++i) {
			if (str1[j - 1] != str2[i - 1]) {
				dp[i][j] = min(
				/*1 for modifying but 2 if not allowed*/1 + dp[i - 1][j - 1],
						1 + min(dp[i][j - 1], dp[i - 1][j]));
			} else {
				dp[i][j] = min(dp[i - 1][j - 1],
						1 + min(dp[i][j - 1], dp[i - 1][j]));
			}
		}
	}
	for (int i = 0; i <=m; ++i) {
	 for (int j = 0; j <=n; ++j) {
	 cout<<dp[i][j]<<" ";
	 }
	 cout<<endl;
	 }
	output_allignment(dp, str1, str2, n, m);
	return dp[m][n];
}



