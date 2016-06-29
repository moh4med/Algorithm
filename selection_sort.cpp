#include"Headers/selection_sort.h"
unsigned long long selestep=0;
unsigned long long selectionsteps(){
	return selestep;
}
void selection_sort(int a[],int n){
	selestep=0;
	for(int i=0;i<n-1;i++){
		int mi=i;
		selestep+=4;
		for (int j = i+1; j < n; ++j) {
			selestep+=2;
			if(a[j]<a[mi]){
				mi=j;
			}
		}
		int val=a[i];
		a[i]=a[mi];
		a[mi]=val;
	}
}
