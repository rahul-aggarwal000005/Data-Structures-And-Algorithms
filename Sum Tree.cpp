bool leaf(node *root) {
	if (root->left == NULL and root->right == NULL) return true;

	return false;
}

bool isSumTree(Node* root)
{
	if (root == NULL or leaf(root)) return true;

	int ls = 0;
	int rs = 0;
	if (isSumTree(root->left) and isSumTree(root->right)) {
		if (root->left == NULL) ls = 0;
		else if (leaf(root->left)) ls = root->left->data;
		else ls = 2 * (root->left->data);

		if (root->right == NULL) rs = 0;
		else if (leaf(root->right)) rs = root->right->data;
		else rs = 2 * (root->right->data);

		return (root->data == (ls + rs));
	}
	return false;

}