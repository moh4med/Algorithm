#include<bits/stdc++.h>
using namespace std;
struct Bracket {
	Bracket(char type, int position) :
			type(type), position(position) {
	}

	bool Matchc(char c) {
		if (type == '[' && c == ']')
			return true;
		if (type == '{' && c == '}')
			return true;
		if (type == '(' && c == ')')
			return true;
		return false;
	}

	char type;
	int position;
};
void Is_Balanced(string text) {
	std::stack<Bracket> opening_brackets_stack;
	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];
		if (next == '(' || next == '[' || next == '{') {
			// Process opening bracket, write your code here
			Bracket x(next, position + 1);
			opening_brackets_stack.push(x);
		} else if (next == ')' || next == ']' || next == '}') {
			// Process closing bracket, write your code here
			if (opening_brackets_stack.empty()) {
				cout << position + 1 << endl;
				return;
			}
			Bracket x = opening_brackets_stack.top();
			opening_brackets_stack.pop();
			if (!x.Matchc(next)) {
				cout << position + 1 << endl;
				return;
			}
		}
	}
	if (opening_brackets_stack.empty()) {
		cout << "Success" << endl;
		return;
	} else {
		while (opening_brackets_stack.size() != 1) {
			opening_brackets_stack.pop();
		}
		Bracket x = opening_brackets_stack.top();
		opening_brackets_stack.pop();
		cout << x.position << endl;
	}
}



