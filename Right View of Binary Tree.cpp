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

void helper(node *root, int &maxLevel, int curLevel, vector<int> &res) {
	if (root == NULL) return;
	if (curLevel > maxLevel) {
		res.push_back(root->data);
		maxLevel = curLevel;
	}
	helper(root->right, maxLevel, curLevel + 1, res);
	helper(root->left, maxLevel, curLevel + 1, res);

}

vector<int> rightView(node *root) {
	vector<int> res;
	int maxLevel = -1;
	helper(root, maxLevel , 0, res);
	return res;

}

void preorder(node *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);

}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = build();
	vector<int> ans = rightView(root);
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}