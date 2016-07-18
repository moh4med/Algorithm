#include<bits/stdc++.h>
using namespace std;
vector<vector<long long> > mi;
vector<vector<long long> > ma;
vector<char> ops;
vector<int> numbers;
long long eval(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	} else if (op == '+') {
		return a + b;
	} else if (op == '-') {
		return a - b;
	} else {
		assert(0);
	}
}
void print_Expression(int i, int j,bool max) {
	if (i == j) {
		cout << numbers[i];
		return ;
	}
	long long ans=ma[i][j];
	if(!max){
		ans=mi[i][j];
	}
	for (int k = i; k < j; ++k) {
		long long a = eval(mi[i][k], mi[k + 1][j], ops[k]);
		long long b = eval(mi[i][k], ma[k + 1][j], ops[k]);
		long long c = eval(ma[i][k], mi[k + 1][j], ops[k]);
		long long d = eval(ma[i][k], ma[k + 1][j], ops[k]);
		if (ans == a) {
			cout<<"(";
			print_Expression(i, k,false);
			cout<<ops[k];
			print_Expression(k+1, j,false);
			cout<<")";
			break;
		}else if (ans == b) {
			cout<<"(";
			print_Expression(i, k,false);
			cout<<ops[k];
			print_Expression(k+1, j,true);
			cout<<")";
			break;
		}else if (ans==c) {
			cout<<"(";
			print_Expression(i, k,true);
			cout<<ops[k];
			print_Expression(k+1, j,false);
			cout<<")";
			break;
		}else if (ans == d) {
			cout<<"(";
			print_Expression(i, k,true);
			cout<<ops[k];
			print_Expression(k+1, j,true);
			cout<<")";
			break;
		}

	}
}
void min_max(int i, int j, long long &x, long long &y) {
	long long w;
	long long z;
	for (int k = i; k < j; ++k) {
		long long a = eval(mi[i][k], mi[k + 1][j], ops[k]);
		long long b = eval(mi[i][k], ma[k + 1][j], ops[k]);
		long long c = eval(ma[i][k], mi[k + 1][j], ops[k]);
		long long d = eval(ma[i][k], ma[k + 1][j], ops[k]);
		w = min(min(a, b), min(c, d));
		z = max(max(a, b), max(c, d));
		x = min(w, x);
		y = max(z, y);
	}
}
long long get_maximum_value(const string &exp) {
	//write your code here
	numbers.resize((exp.size() + 1) / 2);
	ops.resize((exp.size() - 1) / 2);
	int n = numbers.size();
	mi.resize(n, vector<long long>(n, (1 << 30) - 1));
	ma.resize(n, vector<long long>(n, 1 - (1 << 30)));
	for (int i = 0; i < exp.size(); i += 2) {
		numbers[i / 2] = exp[i] - '0';
		//cout << numbers[i / 2] << " ";
	}
	for (int i = 1; i < exp.size(); i += 2) {
		ops[(i - 1) / 2] = exp[i];
		//cout << ops[(i - 1) / 2] << " ";
	}
	for (int i = 0; i < n; ++i) {
		mi[i][i] = numbers[i];
		ma[i][i] = numbers[i];
	}
	for (int gap = 1; gap < n; ++gap) {
		for (int i = 0; i < n - gap; ++i) {
			int j = i + gap;
			//cout<<i<<" "<<j<<endl;
			min_max(i, j, mi[i][j], ma[i][j]);
		}

	}
	/*for (int i = 0; i < n; ++i) {
	 for (int j = 0; j < n; ++j) {
	 cout << ma[i][j] << " ";
	 }
	 cout << endl;
	 }
	 for (int i = 0; i < n; ++i) {
	 for (int j = 0; j < n; ++j) {
	 cout << mi[i][j] << " ";
	 }
	 cout << endl;
	 }*/
	print_Expression(0, n-1,true);
	cout<<endl;
	return ma[0][n - 1];
}
