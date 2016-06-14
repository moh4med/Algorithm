/*
 * merge_sort.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Mohamed
 */
#include"Headers/merge_sort.h"
#include<stdio.h>
unsigned long long mergestep=0;
unsigned long long mergesteps(){
	return mergestep;
}
void merge_sort(int a[],int n){
	merge_sort(a,0,n-1);
}
void merge(int a[], int p, int m, int q) {
	int n1 = m - p + 1;
	int n2 = q - m;
	int left[n1+1];
	int right[n2+1];
	mergestep+=6;
	for (int i = 0; i < n1; ++i) {
		left[i] = a[p + i];
		mergestep++;
	}
	for (int i = 0; i < n2; ++i) {
		right[i] = a[m + i + 1];
		mergestep++;
	}
	left[n1]=(1<<30)-1;
	right[n2]=(1<<30)-1;
	int i=0,j=0;
	for (int k = p; k <=q; ++k) {
		mergestep++;
		if(left[i]<right[j]){
			a[k]=left[i++];
		}else{
			a[k]=right[j++];
		}
	}

}
void merge_sort(int a[], int p, int q) {
	mergestep++;
	if (p < q) {
		mergestep+=3;
		int m = (p + q) / 2;
		merge_sort(a, p, m);
		merge_sort(a, m + 1, q);
		merge(a, p, m, q);
	}
}

