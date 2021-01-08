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

void inorderRec(node *root) {
	if (root == NULL) return;

	inorderRec(root->left);
	cout << root->data << " ";
	inorderRec(root->right);
}

void inorderIter(node *root) {
	stack<node*> s;
	node *cur = root;
	while (!s.empty() or cur != NULL) {
		if (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}
		else {
			cur = s.top();
			s.pop();
			cout << cur->data << " ";
			cur = cur->right;
		}
	}
}
int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = build();
	inorderIter(root);
	return 0;
}