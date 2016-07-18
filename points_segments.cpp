/*
 * points_segments.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
struct item {
  int val;
  int index;
};
bool cmp1(item a, item b) {
  if (a.val == b.val) {
    if (a.index == -1) {
      return 1;
    }
    if (a.index == -2) {
      return 0;
    }
    if (b.index == -1) {
      return 0;
    }
    return 1;
  }
  return a.val < b.val;
}
vector<int> fast_count_segments(vector<int> starts, vector<int> ends,
    vector<int> points) {
  vector<int> cnt(points.size());
  vector<item> items;
  for (int i = 0; i < starts.size(); ++i) {
    item x;
    x.val = starts[i];
    x.index = -1;
    items.push_back(x);
  }
  for (int i = 0; i < ends.size(); ++i) {
    item x;
    x.val = ends[i];
    x.index = -2;
    items.push_back(x);
  }
  for (int i = 0; i < points.size(); ++i) {
    item x;
    x.val = points[i];
    x.index = i;
    items.push_back(x);
  }
  sort(items.begin(), items.end(), cmp1);
  /*cout<<"items:\n";
   for (int i = 0; i < items.size(); ++i) {
   cout << items[i].val << " "<<items[i].index<<endl;
   }*/
  int count = 0;
  for (int i = 0; i < items.size(); ++i) {
    if (items[i].index == -1) {
      count++;
    } else if (items[i].index == -2) {
      count--;
    } else {
      cnt[items[i].index] += count;
    }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends,
    vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}



