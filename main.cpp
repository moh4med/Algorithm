#include<bits/stdc++.h>
using namespace std;
int n;
int dr[] = { 0, -1, 0, 1 }; // E,N,W,S
int dc[] = { 1, 0, -1, 0 }; // R,U,L,D
char ans[] = "RULD";
inline int h1(const vector<int> p) { // heuristic: sum of Manhattan distances (compute all)
	int ans = 0;
	for (int i = 0; i < n * n; i++) {
		int tgt_i = p[i] / n, tgt_j = p[i] % n;
		if (p[i] != n * n - 1)
			ans += abs(i / n - tgt_i) + abs(i % n - tgt_j); // Manhattan distance
	}
	return ans;
}
map<vector<int>, int> g;
vector<vector<int> > states;
inline int f(const vector<int> p) {
	return h1(p) + g[p];
}
struct cmp {
	bool operator()(const int a, const int b) const {
		return f(states[a]) >= f(states[b]);
	}
};
priority_queue<int, vector<int>, cmp> pq;
map<int, pair<int, int> > parent;
inline bool goal(vector<int> p) {
	for (int i = 0; i < n * n; i++)
		if (p[i] != i)
			return false;
	return true;
}

inline bool valid(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < n;
}
void output(int a) {
	if (parent[a].second == -1)
		return;
	output(parent[a].first);
	printf("%c", ans[parent[a].second]);
}
void A() {
	int id = pq.top();
	vector<int> a = states[id];
	pq.pop();
/*	cout << "choose: ";
	for (int i = 0; i < n * n; ++i) {
		cout << a[i] << " ";
	}
	cout << " " << g[a] << " " << h1(a) << " " << " " << f(a) << " "
			<< ans[parent[id].second] << endl;
	cerr << f(a) << endl;*/
	if (!pq.empty()) {
		int id2=pq.top();
		vector<int> b = states[id2];
		/*cout << "choose: ";
		for (int i = 0; i < n * n; ++i) {
			cout << b[i] << " ";
		}
		cout << " " << g[b] << " " << h1(b) << " " << " " << f(b) << " "
				<< ans[parent[id2].second] << endl;
		cerr << f(b) << endl;*/
		if (f(b) < f(a)) {
			pq.pop();
			pq.push(id);
			a = b;
			id=id2;
		}
	}
/*	cout << "choosed: ";
	for (int i = 0; i < n * n; ++i) {
		cout << a[i] << " ";
	}
	cout << " " << g[a] << " " << h1(a) << " " << " " << f(a) << " "
			<< ans[parent[id].second] << endl;*/
	cerr << f(a) << endl;
	if (goal(a)) {				//reach the goal
		output(id);
		printf("\n");
		return;
	}
	int blank;
	blank = find(a.begin(), a.end(), n * n - 1) - a.begin();		//find blank
	int gg = g[a];
	int ii = blank / n, jj = blank % n;	//2d position
	for (int i = 0; i < 4; ++i) {
		if (valid(ii + dr[i], jj + dc[i])) {
			int temp = (ii + dr[i]) * n + (jj + dc[i]);
			vector<int> b = a;
			swap(b[blank], b[temp]);
			if (!g.count(b)) {				//check if explored before
				states.push_back(b);
				int id3=states.size()-1;
				pq.push(id3);
				g[b] = gg + 1;					//update g
				parent[id3]= {id,i};			//update parent
				/*for (int i = 0; i < n * n; ++i) {
					cout << b[i] << " ";
				}
				cout << " " << g[b] << " " << h1(b) << " " << " " << f(b) << " "
						<< ans[parent[id3].second] << endl;*/
			}
		}
	}
	A();
}
bool isSolvable(vector<int> p) {
	int parity = 0;
	int gridWidth = n;
	int row = 0; // the current row we are on
	int blankRow = 0; // the row with the blank tile
	for (int i = 0; i < n * n; i++) {
		if (i % gridWidth == 0) { // advance to next row
			row++;
		}
		if (p[i] == n * n - 1) { // the blank tile
			blankRow = row; // save the row on which encountered
			continue;
		}
		for (int j = i + 1; j < n * n; j++) {
			if (p[i] > p[j] && p[j] != n * n - 1) {
				parity++;
			}
		}
	}
	if (gridWidth % 2 == 0) { // even grid
		if (blankRow % 2 == 0) { // blank on odd row; counting from bottom
			return parity % 2 == 0;
		} else { // blank on even row; counting from bottom
			return parity % 2 != 0;
		}
	} else { // odd grid
		return parity % 2 == 0;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif
	scanf("%d", &n);
	vector<int> p(n * n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &p[i * n + j]);
			if (p[i * n + j] == 0) {
				p[i * n + j] = n * n;
			}
			p[i * n + j]--; // use 0-based indexing
		}
	if (!isSolvable(p)) {
		printf("This puzzle is not solvable.\n");
	} else {
		pq.push(0);
		states.push_back(p);
		g[p] = 0;
		parent[0].second = -1;
		A();
	}
	return 0;
}
