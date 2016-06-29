/*
 * Counting_sort.cpp
 *
 *  Created on: Jun 28, 2016
 *      Author: Mohamed
 */
#include"Headers/Counting_sort.h"
#include <iostream>
using namespace std;
unsigned long long countingstep = 0;
void Counting_sort(int a[], int n, int k) {
	countingstep = 0;
	int c[k + 1];
	int b[n];
	for (int i = 0; i <= k; ++i) {
		c[i] = 0;
		countingstep++;
	}
	for (int i = 0; i < n; ++i) {
		c[a[i]]++;
		countingstep++;
	}
	/*int x = 0;
	for (int i = 0; x < n && i <= k; ++i) {
		countingstep++;
		if (c[i] != 0) {
			countingstep++;
			a[x++] = i;
		}
	}*/

	 for (int i = 1; i <= k; ++i) {
	 c[i] += c[i - 1];
	 countingstep++;
	 }
	 for (int j = n - 1; j >= 0; --j) {
	 b[c[a[j]]-1] = a[j];
	 c[a[j]]--;
	 countingstep+=2;
	 }
	 for (int i = 0; i < n; ++i) {
	 countingstep++;
	 a[i]=b[i];
	 }
}
unsigned long long Countingsteps() {
	return countingstep;
}

