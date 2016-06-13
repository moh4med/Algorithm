#include"Headers/insertion_sort.h"
void insertion_sort(int a[],int n){
	for(int i=1;i<n;i++){
		int j=i-1,val=a[i];
		while(j>=0&&a[j]>val){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=val;
	}
}


