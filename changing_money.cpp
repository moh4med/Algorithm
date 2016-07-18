#include<bits/stdc++.h>
using namespace std;
int change_money(int m) {
	int c[] = { 10, 5, 1 };
	int i = 0;
	int tot = 0;
	while (m > 0) {
		while (m < c[i]) {
			i++;
		}
		tot += m / c[i];
		m = m % c[i];
		i++;
	}
	return tot;
}
int change_money_recursive(int m, vector<int> coins) {
	if (m == 0) {
		return 0;
	}
	if (m < 0) {
		return -1;
	}
	int min_number = (1 << 30) - 1;
	for (int i = 0; i < coins.size(); ++i) {	//coins are sorted
		if (m >= coins[i]) {
			min_number = min(min_number,
					change_money_recursive(m - coins[i], coins) + 1);
		} else {
			break;
		}
	}
	if (min_number == (1 << 30) - 1) {
		return -1;
	}
	return min_number;
}
int change_money_memoized(int m, vector<int> coins, vector<int>&ans) {
	if (m == 0) {
		return 0;
	}
	int min_number = (1 << 30) - 1;
	for (int i = 0; i < coins.size(); ++i) {	//coins are sorted
		if (m >= coins[i]) {
			if (ans[m - coins[i]] == -1) {
				min_number = min(min_number,
						change_money_recursive(m - coins[i], coins) + 1);
			} else {
				min_number = min(min_number, ans[m - coins[i]] + 1);
			}

		} else {
			break;
		}
	}
	ans[m] = min_number;
	if (ans[m] == (1 << 30) - 1) {
		return 0;
	}
	return ans[m];

}
int change_money_dp(int m, vector<int> coins) {
	vector<int> ans(m + 1, 0);
	for (int i = 1; i <= m; ++i) {
		ans[i] = (1 << 30) - 1;
	}
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j < coins.size(); ++j) {	//coins are sorted
			if (i >= coins[j]) {
				ans[i] = min(ans[i], ans[i - coins[j]] + 1);
			} else {
				break;
			}
		}
		//cout<<ans[i]<<endl;
	}
	if (ans[m] == (1 << 30) - 1) {
		return 0;
	}
	return ans[m];
}
