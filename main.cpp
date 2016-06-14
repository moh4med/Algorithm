#include<bits/stdc++.h>
#include"Headers/Graph.h"
using namespace std;
int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	GList a(10);
	GMatrix b(10);
	a.addedge(8, 2);
	a.addedge(8, 6);
	b.addedge(6, 4);
	for(auto i:a.adjacents(8))cout<<i<<endl;
	for(auto i:b.adjacents(6))cout<<i<<endl;
	return 0;
}
