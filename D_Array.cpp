/*
 * D_Array.cpp
 *
 *  Created on: Jul 20, 2016
 *      Author: Mohamed
 */
#include<iostream>
#include"Headers/D_Array.h"
using namespace std;
DArr::DArr() {
	arr = new int[1];
	capacity = 1;
	size = 0;
}
DArr::DArr(int s) {
	arr = new int[s];
	capacity = s;
	size = 0;
}
int DArr::get(int i) {
	if (i < 0 || i >= size) {
		cout << "Error index out of range\n";
	}
	return arr[i];
}
int DArr::size_() {
	return size;
}
int DArr::capacity_() {
	return capacity;
}
void DArr::set(int i, int val) {
	if (i < 0 || i >= size) {
		cout << "Error index out of range\n";
	}
	arr[i] = val;
}
void DArr::pushback(int val) {
	if (size == capacity - 1) {
		int *new_arr=new int[2 * capacity];
		for (int i = 0; i < size; ++i) {
			new_arr[i] = arr[i];
		}
//		delete[] arr;
		capacity *= 2;
		arr = new_arr;
	}
	arr[size] = val;
	size++;

}
void DArr::remove(int i) {
	if (i < 0 || i >= size) {
		cout << "Error index out of range\n";
	}
	for (int j = i; j < size - 1; ++j) {
		arr[j] = arr[j + 1];
	}
	size--;
}

