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

void postorderRec(node *root) {
	if (root == NULL) return;

	postorderRec(root->left);
	postorderRec(root->right);
	cout << root->data << " ";
}

void postorderIter(node *root) {
	stack<node*> s;
	stack<node*> t;
	s.push(root);
	while (!s.empty()) {
		node *x = s.top();
		s.pop();
		t.push(x);
		if (x->left != NULL) {
			s.push(x->left);
		}
		if (x->right != NULL) {
			s.push(x->right);
		}
	}

	while (!t.empty()) {
		node *x = t.top();
		t.pop();
		cout << x->data << " ";
	}

}
int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = build();
	postorderIter(root);
	return 0;
}