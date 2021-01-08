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

void helper(node *root, int cur, int &maxSlop, unordered_map<int, vector<int>> &mp) {
	if (root == NULL) return;
	maxSlop = max(maxSlop, cur);
	mp[cur].push_back(root->data);
	helper(root->left, cur + 1, maxSlop, mp);
	helper(root->right, cur, maxSlop, mp);

}

vector<int> solve(node *root) {
	vector<int> res;
	int maxSlop = -1;
	unordered_map<int, vector<int>> mp;
	helper(root, 0, maxSlop, mp);
	for (int i = 0; i <= maxSlop; i++) {
		for (auto x : mp[i]) {
			res.push_back(x);
		}
	}
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
	vector<int> ans = solve(root);
	for (auto x : ans) {
		cout << x << " ";
	}

	return 0;
}