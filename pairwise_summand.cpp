#include<bits/stdc++.h>
using namespace std;
vector<int> optimal_summands(int n) {
	vector<int> summands;
	//write your code here
	int i=1;
	while(n-i>i){
		summands.push_back(i);
		n-=i;
		i++;
	}
	summands.push_back(n);
	return summands;
}
