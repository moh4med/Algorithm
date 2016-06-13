#include"Headers/selection_sort.h"
void selection_sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int mi=i;
		for (int j = i+1; j < n; ++j) {
			if(a[j]<a[mi]){
				mi=j;
			}
		}
		int val=a[i];
		a[i]=a[mi];
		a[mi]=val;
	}
}
