#include"Headers/Randomized_select.h"
#include <algorithm>
using namespace std;
int Randomized_select(int a[],int p,int r,int i){
	if(p==r){
		return a[p];
	}
	int q=R_partition(a, p, r);
	int k=q-p;
	if(k==i)return a[q];
	else if (i<k){
		return Randomized_select(a, p, q-1, i);
	}else{
		return Randomized_select(a, q+1, r, i-k-1);
	}
}
int R_partition(int a[], int p, int r) {
	int ran = rand() % (r - p + 1) + p;
	swap(a[ran],a[r]);
	int piv = a[r];
	int i = p;
	for (int j = p; j < r; ++j) {
		if (a[j] <= piv) {
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[r],a[i]);
	return i;
}


