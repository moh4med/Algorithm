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
bool cmp(struct item a, struct item b) {
	double r1 = (double) a.value / a.weight;
	double r2 = (double) b.value / b.weight;
	return r1 > r2;
}
double fraction_knapsack(int cap, item a[], int n) {
	sort(a, a + n, cmp);
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



