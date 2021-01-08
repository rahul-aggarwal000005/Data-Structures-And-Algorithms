#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *left;
	node *right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *build() {
	int d;
	cin >> d;
	if (d == -1) return NULL;

	node *root = new node(d);
	root->left = build();
	root->right = build();
	return root;
}

void preorderRec(node *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorderRec(root->left);

	preorderRec(root->right);
}

void preorderIter(node *root) {
	stack<node*> s;
	node *cur = root;
	s.push(cur);
	while (!s.empty()) {
		node *t = s.top();
		s.pop();
		cout << t->data << " ";
		if (t->right != NULL) {
			s.push(t->right);
		}
		if (t->left != NULL) {
			s.push(t->left);
		}
	}
}
int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = build();
	preorderIter(root);
	return 0;
}