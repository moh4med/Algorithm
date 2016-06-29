/*
 * Radix_sort.cpp
 *
 *  Created on: Jun 28, 2016
 *      Author: Mohamed
 */
#include"Headers/Radix_sort.h"
unsigned long long radixstep;
unsigned long long Radixsteps() {
	return radixstep;
}
void countsort(int a[], int n, int ex) {
	int c[10];
	int b[n];
	for (int i = 0; i < 10; ++i) {
		c[i] = 0;
		radixstep++;
	}
	for (int i = 0; i < n; ++i) {
		c[(a[i] / ex) % 10]++;
		radixstep++;
	}
	for (int i = 1; i < 10; ++i) {
		c[i] += c[i - 1];
		radixstep++;
	}
	for (int j = n - 1; j >= 0; --j) {
		b[c[(a[j] / ex) % 10] - 1] = a[j];
		c[(a[j] / ex) % 10]--;
		radixstep += 2;
	}
	for (int i = 0; i < n; ++i) {
		radixstep++;
		a[i] = b[i];
	}
}

void Radix_sort(int a[], int n) {
	radixstep=0;
	radixstep++;
	int m = a[0];
	for (int i = 1; i < n; ++i) {
		radixstep++;
		if (a[i] > m) {
			radixstep++;
			m = a[i];
		}
	}
	for (int i = 1; m / i > 0; i *= 10) {
		radixstep++;
		countsort(a, n, i);
	}
}

