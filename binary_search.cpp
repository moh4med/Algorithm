/*
 * binary_search.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Mohamed
 */
#include "Headers/binary_search.h"
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
int binarysearch(int a[],int n,int x){
	return binarysearch(a, 0, n-1, x);
}



