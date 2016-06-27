/*
 * Graph.h
 *
 *  Created on: Jun 14, 2016
 *      Author: Mohamed
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>
#pragma once
class GList{
private:
	std::vector< std::vector<int> > a;
public:
	GList(int n);
	void addedge(int from,int to);
	std::vector<int> adjacents(int from);
	bool IsAdjacent(int from ,int to);
};
class GMatrix{
	std::vector< std::vector<bool> > a;
public:
	GMatrix(int n);
	void addedge(int from,int to);
	std::vector<int> adjacents(int from);
	bool IsAdjacent(int from ,int to);
};


#endif /* GRAPH_H_ */
