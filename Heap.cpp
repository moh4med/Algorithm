/*
 * Heap.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
class HeapBuilder {
private:
	vector<int> data_;
	vector<pair<int, int> > swaps_;
	int n;
	void WriteResponse() const {
		cout << swaps_.size() << "\n";
		for (int i = 0; i < swaps_.size(); ++i) {
			cout << swaps_[i].first << " " << swaps_[i].second << "\n";
		}
	}

	void ReadData() {
		cin >> n;
		data_.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> data_[i];
	}
	void sift_down(int i) {
		int minimum = i;
		int l = 2 * i + 1;
		int r = l + 1;
		if (l < n && data_[l] < data_[minimum]) {
			minimum = l;
		}
		if (r < n && data_[r] < data_[minimum]) {
			minimum = r;
		}
		if(minimum!=i){
			swap(data_[i],data_[minimum]);
			 swaps_.push_back(make_pair(i, minimum));
			 sift_down(minimum);
		}
	}
	void GenerateSwaps() {
		swaps_.clear();
		// The following naive implementation just sorts
		// the given sequence using selection sort algorithm
		// and saves the resulting sequence of swaps.
		// This turns the given array into a heap,
		// but in the worst case gives a quadratic number of swaps.
		//
		// TODO: replace by a more efficient implementation
		for (int i = (n / 2) - 1; i >= 0; --i) {
			sift_down(i);
		}
	}

public:
	void Solve() {
		ReadData();
		GenerateSwaps();
		WriteResponse();
	}
};



