/*
 * poly_mult.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
vector<int> poly_multipication(vector<int> a, vector<int> b) {
	vector<int> ans(a.size() + b.size() - 1);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			ans[i + j] += a[i] * b[j];
		}
	}
	return ans;
}
vector<int> poly_multipication_recursive2(vector<int> a, vector<int> b, int sa,
		int ea, int sb, int eb) {
	int n = ea - sa, m = eb - sb;
	vector<int> ans(n + m - 1);
	if (n == 1) {
		for (int i = sb; i < eb; ++i) {
			ans[i - sb] = a[sa] * b[i];
		}
		return ans;
	}
	if (m == 1) {
		for (int i = sa; i < ea; ++i) {
			ans[i - sa] = b[sb] * a[i];
		}
		return ans;
	}
	vector<int> ans1 = poly_multipication_recursive2(a, b, sa + n / 2, ea,
			sb + m / 2, eb);
	vector<int> ans2 = poly_multipication_recursive2(a, b, sa + n / 2, ea, sb,
			sb + m / 2);
	vector<int> ans3 = poly_multipication_recursive2(a, b, sa, sa + n / 2,
			sb + m / 2, eb);
	vector<int> ans4 = poly_multipication_recursive2(a, b, sa, sa + n / 2, sb,
			sb + m / 2);
	for (int i = 0; i < ans1.size(); ++i) {
		ans[i + n / 2 + m / 2] += ans1[i];
	}
	for (int i = 0; i < ans2.size(); ++i) {
		ans[i + n / 2] += ans2[i];
	}
	for (int i = 0; i < ans3.size(); ++i) {
		ans[i + m / 2] += ans3[i];
	}
	for (int i = 0; i < ans4.size(); ++i) {
		ans[i] += ans4[i];
	}
	return ans;
}
vector<int> poly_multipication_recursive(vector<int> a, vector<int> b) {
	int n = a.size(), m = b.size();
	vector<int> ans(n + m - 1);
	if (n == 1) {
		for (int i = 0; i < m; ++i) {
			ans[i] = a[0] * b[i];
		}
		return ans;
	}
	if (m == 1) {
		for (int i = 0; i < n; ++i) {
			ans[i] = b[0] * a[i];
		}
		return ans;
	}
	vector<int> d0(n / 2), d1(n - n / 2), e0(m / 2), e1(m - m / 2);
	for (int i = n / 2; i < n; ++i) {
		d1[i - n / 2] = a[i];
	}
	for (int i = 0; i < n / 2; ++i) {
		d0[i] = a[i];
	}
	for (int i = m / 2; i < m; ++i) {
		e1[i - m / 2] = b[i];
	}
	for (int i = 0; i < m / 2; ++i) {
		e0[i] = b[i];
	}
	vector<int> ans1 = poly_multipication_recursive(d1, e1);
	vector<int> ans2 = poly_multipication_recursive(d1, e0);
	vector<int> ans3 = poly_multipication_recursive(d0, e1);
	vector<int> ans4 = poly_multipication_recursive(d0, e0);
	for (int i = 0; i < ans1.size(); ++i) {
		ans[i + n / 2 + m / 2] += ans1[i];
	}
	for (int i = 0; i < ans2.size(); ++i) {
		ans[i + n / 2] += ans2[i];
	}
	for (int i = 0; i < ans3.size(); ++i) {
		ans[i + m / 2] += ans3[i];
	}
	for (int i = 0; i < ans4.size(); ++i) {
		ans[i] += ans4[i];
	}
	return ans;
}
vector<int> poly_multipication_recursive3(vector<int> a, vector<int> b) {
	int n = a.size(), m = b.size();
	vector<int> ans(n + m - 1);
	if (n == 1) {
		for (int i = 0; i < m; ++i) {
			ans[i] = a[0] * b[i];
		}
		return ans;
	}
	if (m == 1) {
		for (int i = 0; i < n; ++i) {
			ans[i] = b[0] * a[i];
		}
		return ans;
	}
	vector<int> d0(n / 2), d1(n - n / 2), e0(m / 2), e1(m - m / 2);
	for (int i = n / 2; i < n; ++i) {
		d1[i - n / 2] = a[i];
	}
	for (int i = 0; i < n / 2; ++i) {
		d0[i] = a[i];
	}
	for (int i = m / 2; i < m; ++i) {
		e1[i - m / 2] = b[i];
	}
	for (int i = 0; i < m / 2; ++i) {
		e0[i] = b[i];
	}
	vector<int> ans1 = poly_multipication_recursive(d1, e1);
	vector<int> ans2 = poly_multipication_recursive(d0, e0);
	for (int i = 0; i < ans1.size(); ++i) {
		ans[i + n / 2 + m / 2] += ans1[i];
	}
	for (int i = 0; i < ans2.size(); ++i) {
		ans[i] += ans2[i];
	}
	if (n == m) {
		for (int i = 0; i < min(d1.size(), d0.size()); ++i) {
			d1[i] += d0[i];
		}
		for (int i = 0; i < min(e1.size(), e0.size()); ++i) {
			e1[i] += e0[i];
		}
		vector<int> ans3 = poly_multipication_recursive(d1, e1);
		for (int i = 0; i < ans3.size(); ++i) {
			ans[i + n / 2] += ans3[i];
			if (i < ans1.size()) {
				ans[i + n / 2] -= ans1[i];
			}
			if (i < ans2.size()) {
				ans[i + n / 2] -= ans2[i];
			}
		}
	} else {
		vector<int> ans3 = poly_multipication_recursive(d1, e0);
		vector<int> ans4 = poly_multipication_recursive(d0, e1);
		for (int i = 0; i < ans3.size(); ++i) {
			ans[i + n / 2] += ans3[i];
		}
		for (int i = 0; i < ans4.size(); ++i) {
			ans[i + m / 2] += ans4[i];
		}
	}

	return ans;
}

