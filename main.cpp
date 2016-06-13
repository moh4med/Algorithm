#include<bits/stdc++.h>
#include"Headers/binary_search.h"
using namespace std;
int main() {
	int n;
	srand(time(NULL));
	n=rand()%100000+1;
	int a[]={1,2,3,5,14,60,90,800};
	cout<<binarysearch(a, 8, 90);
//	for(auto i:a)cout<<i<<endl;
	return 0;
}
