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

void helper(node *root, int hr, int curLevel, int &minHr, int &maxHr, unordered_map<int, pair<int, int>> &mp) {
	if (root == NULL) return;
	minHr = min(minHr, hr);
	maxHr = max(maxHr, hr);
	if (mp.find(hr) != mp.end()) {
		if (curLevel >= mp[hr].second) {
			mp.erase(hr);
			mp[hr] = make_pair(root->data, curLevel);
		}
	} else {
		mp[hr] = make_pair(root->data, curLevel);
	}
	helper(root->left, hr - 1, curLevel + 1, minHr, maxHr, mp);
	helper(root->right, hr + 1, curLevel + 1, minHr, maxHr, mp);

}

vector<int> topView(node *root) {
	vector<int> res;
	int hr = 0;
	int minHr = 0;
	int maxHr = 0;
	unordered_map<int, pair<int, int>> mp; // pair<hr,pair<val,level>>
	helper(root, hr, 0, minHr, maxHr, mp);

	for (int i = maxHr; i >= minHr; i--) {
		res.push_back(mp[i].first);
	}
	reverse(res.begin(), res.end());

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
	// preorder(root);
	vector<int> ans = topView(root);
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}