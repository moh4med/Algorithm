#include<bits/stdc++.h>
#include"Headers/merge_sort.h"
#include"Headers/insertion_sort.h"
#include"Headers/selection_sort.h"
#include"Headers/merge_modified_sort.h"
#include"Headers/bubble_sort.h"
using namespace std;
int main() {
	//freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	for (int n = 1; n < 1000; n++) {
		srand(time(NULL));
		int a[n];
		int b[n];
		int c[n];
		int d[n];
		int e[n];
		for (int i = 0; i < n; ++i) {
			a[i] = rand() % 10000000 + 1;
			b[i] = a[i];
			c[i] = a[i];
			d[i] = a[i];
			e[i]=a[i];
		}
		std::clock_t start;
		double duration;
		start = std::clock();
		merge_sort(a, n);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		cout << n << " merge: " << mergesteps() << "  ";
		start = std::clock();
		insertion_sort(b, n);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		cout << "inser: " << insertionsteps() << " ";
		start = std::clock();
		selection_sort(d, n);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		cout << "selec: " << selectionsteps() << " ";
		start = std::clock();
		bubble_sort(e, n);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		cout << "bubb: " << buublesteps() << " ";
		start = std::clock();
		merge_sort_modified(c, n);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		cout << "modif: " << mergemodisteps() << " " << endl;
	}
	return 0;
}
