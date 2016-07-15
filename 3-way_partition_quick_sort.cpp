/*
 * 3-way_partition_quick_sort.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
void partition2(vector<int> &a, int l, int r, int& m, int& w) {
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	x = j;
	for (int i = l; i < x; ++i) {
		if (a[i] == a[j]) {
			swap(a[i], a[--x]);
		}
	}
	m = j + 1;
	w = x-1;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m, w;
	partition2(a, l, r, m, w);
	randomized_quick_sort(a, l, w);
	randomized_quick_sort(a, m, r);
}




