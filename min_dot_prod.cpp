#include<bits/stdc++.h>
using namespace std;
long long min_dot_product(vector<int> a, vector<int> b) {
	// write your code here
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	long long result = 0;
	for (size_t i = 0; i < a.size(); i++) {
		result += ((long long) a[i]) * b[i];
	}
	return result;
}
