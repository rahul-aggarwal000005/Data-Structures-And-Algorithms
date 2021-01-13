
int convert(Node *root) {
	if (root == NULL) return 0;

	int rd = root->data;

	int ltd = covert(root->left);
	int rtd = convert(root->right);

	root->data = ltd + rtd;

	return (root->data + rd);

}

void toSumTree(Node *node)
{
	convert(node);
}
