#include<bits/stdc++.h>
using namespace std;
class TreeHeight {
	int n;
	std::vector<int> parent;
	vector<int> dp;

public:
	void read() {
		std::cin >> n;
		parent.resize(n);
		dp.resize(n, 0);
		bool ok = false;
		for (int i = 0; i < n; i++) {
			std::cin >> parent[i];
			if (parent[i] == -1) {
				dp[i] = 1;
				ok = true;
			}
		}
		if (!ok) {
			dp[0] = 1;
		}
	}
	int height_recur(int i) {
		if (dp[i] != 0) {
			return dp[i];
		}
		dp[i] = height_recur(parent[i]) + 1;
		return dp[i];
	}
	int compute_height() {
		// Replace this code with a faster implementation
		int maxHeight = 0;
		for (int vertex = 0; vertex < n; vertex++) {
			int height = height_recur(vertex);
			maxHeight = std::max(maxHeight, height);
		}
		return maxHeight;
	}
};



