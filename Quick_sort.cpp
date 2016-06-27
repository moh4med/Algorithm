#include"Headers/Quick_sort.h"
#include<iostream>
#include <algorithm>
using namespace std;
unsigned long long quickstep = 0;
unsigned long long quicksteps() {
	return quickstep;
}

int partition(int a[], int p, int r) {
	quickstep += 8;
	/*int ran = rand() % (r - p + 1) + p;
	swap(a[ran],a[r]);*/
	int piv = a[r];
	int i = p;
	for (int j = p; j < r; ++j) {
		quickstep++;
		if (a[j] <= piv) {
			quickstep += 3;
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[r],a[i]);
	return i;
}
void Quick_sort(int a[], int p, int r) {
	quickstep++;
	if (p < r) {
		quickstep += 3;
		int q = partition(a, p, r);
		Quick_sort(a, p, q - 1);
		Quick_sort(a, q + 1, r);
	}
}

