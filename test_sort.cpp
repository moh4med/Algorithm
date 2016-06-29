#include<bits/stdc++.h>
#include<time.h>
#include"Headers/Quick_sort.h"
#include"Headers/merge_modified_sort.h"
#include"Headers/insertion_sort.h"
#include"Headers/Counting_sort.h"
#include"Headers/Radix_sort.h"
using namespace std;
int test() {
	//freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	cout << setw(15) << left << "numbers" << setw(15) << "merge_sort"
			<< setw(15) << "merge time" << setw(15) << "quick_sort" << setw(15)
			<< "quick_time" << setw(15) << "insertion_sort" << setw(15)
			<< "insertion_time" << setw(15) << "Counting_sort" << setw(15)
			<< "Counting_time" << setw(15) << "Radix_sort" << setw(15)
			<< "Radix_time" << endl;
	srand(time(NULL));
	for (int i = 1; i < 100000; i += 50) {
		int a[i], b[i], c[i], d[i], e[i];
		for (int j = 0; j < i; ++j) {
			a[j] = rand();
			b[j] = a[j];
			c[j] = a[j];
			d[j] = a[j];
			e[j] = a[j];
		}
		double x = clock();
		merge_sort_modified(a, i);
		cout << setw(15) << left << i << setw(15) << mergemodisteps()
				<< setw(15) << clock() - x;
		x = clock();
		Quick_sort(b, i);
		cout << left << setw(15) << quicksteps() << setw(15) << clock() - x;
		x = clock();
		insertion_sort(c, i);
		cout << left << setw(15) << insertionsteps() << setw(15) << clock() - x;
		x = clock();
		int k = *max_element(a, a + i);
		Counting_sort(d, i, k);
		cout << left << setw(15) << Countingsteps() << setw(15) << clock() - x;
		x = clock();
		Radix_sort(e, i);
		cout << left << setw(15) << Radixsteps() << setw(15) << clock() - x
				<< endl;
		x = clock();

	}
	return 0;
}
