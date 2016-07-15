/*
 * major_element.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
int find_candidate(vector<int> &a, int n){
	int cnt=1,maj=a[0];
	for (int i = 1; i < n; ++i) {
		if(a[i]==maj){
			cnt++;
		}else{
			cnt--;
		}
		if(cnt==0){
			cnt++;
			maj=a[i];
		}
	}
	return maj;
}
int is_major(vector<int> &a, int n,int can){
	int cnt=0;
	for (int i = 0; i < n; ++i) {
		if(a[i]==can){
			cnt++;
		}
	}
	if(cnt>(n/2)){
		return 1;
	}else{
		return 0;
	}
}
int get_majority_element(vector<int> &a, int n) {
	int can=find_candidate(a,n);
	return is_major(a,n,can);
}



