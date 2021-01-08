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


void preorder(node *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);

}

void leftBoundary(node *root, vector<int> &res) {
	if (root == NULL) return;
	if (root->left) {
		res.push_back(root->data);
		leftBoundary(root->left, res);
	}
	else if (root->right) {
		res.push_back(root->data);
		leftBoundary(root->right, res);
	}
}


void rightBoundary(node *root, vector<int> &res) {
	if (root == NULL) return;
	if (root->right) {
		rightBoundary(root->right, res);
		res.push_back(root->data);
	}
	else if (root->left) {
		rightBoundary(root->left, res);
		res.push_back(root->data);
	}
}

void leafNode(node *root, vector<int> &res) {
	if (root == NULL) return;

	leafNode(root->left, res);
	if (root->left == NULL and root->right == NULL) res.push_back(root->data);
	leafNode(root->right, res);
}

vector<int> printBoundary(node *root) {
	vector<int> res;
	res.push_back(root->data);
	leftBoundary(root->left, res);
	leafNode(root->left, res);
	leafNode(root->right, res);
	rightBoundary(root->right, res);
	return res;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = build();
	vector<int> ans = printBoundary(root);
	for (auto x : ans) {
		cout << x << " ";
	}

	return 0;
}