/*
 * Inversion.cpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
long long inversions=0;
void merge1(int a[], int p, int m, int q) {
	int n1 = m - p + 1;
	int n2 = q - m;
	int left[n1+1];
	int right[n2+1];
	for (int i = 0; i < n1; ++i) {
		left[i] = a[p + i];
	}
	for (int i = 0; i < n2; ++i) {
		right[i] = a[m + i + 1];
	}
	left[n1]=(1<<30)-1;
	right[n2]=(1<<30)-1;
	int i=0,j=0,ii;
	for (int k = p; k <=q; ++k) {
		if(left[i]<=right[j]){
			a[k]=left[i++];
		}else if(left[i]>right[j]&&i!=n1){
			a[k]=right[j++];
			inversions+=n1-i;
		}
	}

}
void merge_sort1(int a[], int p, int q) {
	if (p < q) {
		int m = (p + q) / 2;
		merge_sort1(a, p, m);
		merge_sort1(a, m + 1, q);
		merge1(a, p, m, q);
	}
}
long long number_of_inversion(int a[],int n){
	inversions=0;
	merge_sort1(a,0,n-1);
	return inversions;
}



