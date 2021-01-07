int height(struct Node* node) {
	// code here
	if (node == NULL) return 0;
	int lst = height(node->left);
	int rst = height(node->right);
	return max(lst, rst) + 1;
}