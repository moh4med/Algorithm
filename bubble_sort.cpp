#include"Headers/bubble_sort.h"
unsigned long long bubstep = 0;
unsigned long long buublesteps() {
	return bubstep;
}
void bubble_sort(int a[], int n) {
	bubstep=0;
	bool swaped=true;
	int i=0;
	while(swaped){
		swaped=false;
		bubstep ++;
		for (int j = n - 1; j > i; --j) {
			bubstep++;
			if (a[j] < a[j-1]) {
				swaped=true;
				bubstep+=3;
				int val = a[j];
				a[j] = a[j-1];
				a[j-1] = val;
			}
		}
		i++;
	}
}
