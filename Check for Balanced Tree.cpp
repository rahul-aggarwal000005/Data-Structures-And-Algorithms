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


pair<int, int> helper(node *root) {
	pair<int, int> p;
	if (root == NULL) {
		p.first = 0;
		p.second = true;
		return p;
	}

	pair<int, int> lst = helper(root->left);
	pair<int, int> rst = helper(root->right);

	int lh = lst.first;
	int rh = rst.first;

	p.first = max(lh, rh) + 1;
	if (abs(lh - rh) <= 1 and lst.second and rst.second) {
		p.second = true;
	}
	else {
		p.second = false;
	}

	return p;

}

bool isBalanced(node *root) {
	pair<int, int> ans;
	ans = helper(root);
	return ans.second;
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
	// preorder(root);
	if (isBalanced(root)) {
		cout << "balanced";
	} else {
		cout << "Not balanced";
	}
	return 0;
}