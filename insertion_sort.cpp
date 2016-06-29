#include"Headers/insertion_sort.h"
unsigned long long insertionstep=0;
#include <iostream>
using namespace std;
unsigned long long insertionsteps(){
	return insertionstep;
}
void insertion_sort(int a[],int n){
	insertionstep=0;
	for(int i=1;i<n;i++){
		int j=i-1,val=a[i];
		insertionstep+=3;
		while(j>=0&&a[j]>val){
			insertionstep+=2;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=val;
	}
}


