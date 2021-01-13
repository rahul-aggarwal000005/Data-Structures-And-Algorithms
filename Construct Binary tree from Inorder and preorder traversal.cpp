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

node *buildTree(int in[], int pre[], int s, int e) {
	if (s > e) return NULL;

	static int pi = 0;
	node *root = new node(pre[pi]);

	int idx = -1;
	for (int i = s; i <= e; i++) {
		if (in[i] == pre[pi]) {
			idx = i;
			break;
		}
	}

	pi++;
	if (idx != -1) {
		root->left = buildTree(in, pre, s, idx - 1);
		root->right = buildTree(in, pre, idx + 1, e);
	}
	return root;
}

node *build(int in[], int pre[], int n) {
	node *root = buildTree(in, pre, 0, n - 1);
	return root;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int in[n];
	int pre[n];
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}

	node *root = build(in, pre, n);
	preorder(root);

	return 0;
}