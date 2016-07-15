/*
 * binary_search.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Mohamed
 */
#include "Headers/binary_search.h"
#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int s,int e,int x){
	if(e<s)return -1;
	int mid=(s+e)/2;
	if(a[mid]==x){
		return mid;
	}
	if(a[mid]>x){
		return (binarysearch(a, s, mid-1, x));
	}else{
		return (binarysearch(a, mid+1,e, x));
	}
}
int binary_search_iter(const vector<int> &a, int x) {
	int left = 0, right = (int) a.size();
	while(left<=right){
		int mid=left+(right-left)/2;
		if(a[mid]==x){
			return mid;
		}else if(a[mid]>x){
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	return -1;
	//write your code here
}
int binarysearch(int a[],int n,int x){
	return binarysearch(a, 0, n-1, x);
}



