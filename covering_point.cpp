#include<bits/stdc++.h>
using namespace std;
struct Segment {
	int start, end;
};
bool cmp(Segment a, Segment b) {
	return a.end < b.end;
}
vector<int> optimal_points(vector<Segment> &segments) {
	sort(segments.begin(),segments.end(),cmp);
	vector<int> points;
	//write your code here
	int p=-1;
	for (size_t i = 0; i < segments.size(); ++i) {
		if(p>segments[i].end||p<segments[i].start){
			p=segments[i].end;
			points.push_back(p);
		}
	}
}
