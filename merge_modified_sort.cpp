/*
 * merge_sort.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Mohamed
 */
#include"Headers/merge_modified_sort.h"
#include<stdio.h>
unsigned long long mergemodstep = 0;
unsigned long long mergemodisteps() {
	return mergemodstep;
}
void merge_sort_modified(int a[], int n) {
	merge_sort_modified(a, 0, n - 1);
}
void merge_modified(int a[], int p, int m, int q) {
	int n1 = m - p + 1;
	int n2 = q - m;
	int left[n1 + 1];
	int right[n2 + 1];
	mergemodstep+=6;
	for (int i = 0; i < n1; ++i) {
		left[i] = a[p + i];
		mergemodstep++;
	}
	for (int i = 0; i < n2; ++i) {
		right[i] = a[m + i + 1];
		mergemodstep++;
	}
	left[n1] = (1 << 30) - 1;
	right[n2] = (1 << 30) - 1;
	int i = 0, j = 0;
	for (int k = p; k <= q; ++k) {
		mergemodstep++;
		if (left[i] < right[j]) {
			a[k] = left[i++];
		} else {
			a[k] = right[j++];
		}
	}

}
void insert_sort(int a[],int p,int q){
	for(int i=p+1;i<=q;i++){
		int j=i-1,val=a[i];
		mergemodstep+=3;
		while(j>=p&&a[j]>val){
			mergemodstep+=2;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=val;
	}
}
void merge_sort_modified(int a[], int p, int q) {
	if (p < q) {
		mergemodstep+=3;
		if (q - p <= 50) {
			insert_sort(a,p,q);
		} else {
			int m = (p + q) / 2;
			merge_sort_modified(a, p, m);
			merge_sort_modified(a, m + 1, q);
			merge_modified(a, p, m, q);
		}
	}
}

