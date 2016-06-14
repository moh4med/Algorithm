/*
 * Graph.cpp
 *
 *  Created on: Jun 14, 2016
 *      Author: Mohamed
 */
#include"Headers/Graph.h"
GList::GList(int n) {
	a.resize(n + 1);
}
GMatrix::GMatrix(int n) {
	a.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		a[i].resize(n + 1);
	}
}
void GList::addedge(int from, int to) {
	(this->a)[from].push_back(to);
}
void GMatrix::addedge(int from, int to) {
	(this->a)[from][to] = true;
}
std::vector<int> GMatrix::adjacents(int from) {
	std::vector<int> ad;
	for (int i = 1; i < a.size(); i++) {
		if (a[from][i] == 1) {
			ad.push_back(i);
		}
	}
	return ad;
}
bool GMatrix::IsAdjacent(int from, int to) {
	return (this->a)[from][to];
}
std::vector<int> GList::adjacents(int from) {
	return a[from];
}
bool GList::IsAdjacent(int from, int to) {
for(int i=0;i<a[from].size();i++) {
	if(a[from][i]==to) {
		return true;
	}
	return false;
}
}
