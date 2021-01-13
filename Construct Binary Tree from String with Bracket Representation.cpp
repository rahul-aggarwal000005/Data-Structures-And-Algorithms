#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void preorder(node *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int findClosing(string s, int start, int end) {
	if (start > end) return -1;
	stack<char> st;
	for (int i = start; i <= end; i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.top() == '(') {
				st.pop();
				if (st.empty()) return i;
			}
		}
	}

	return -1;
}

node *build(string s, int start, int end) {
	/*
		4  (2(3)(1))  (6(5))
	*/
	if (start > end) return NULL;
	node *root = new node(s[start] - '0');
	int idx = -1;

	if (start + 1 <= end and s[start + 1] == '(') {
		idx = findClosing(s, start + 1, end);
	}

	if (idx != -1) {
		root->left = build(s, start + 2, idx - 1);
		root->right = build(s, idx + 2, end - 1);
	}

	return root;

}
int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	node *root = build(s, 0, s.length() - 1);
	preorder(root);


	return 0;
}