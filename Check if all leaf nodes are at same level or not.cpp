typedef Node node;

bool help(node *root, int level, int &maxLevel) {
    if (root == NULL) return true;
    if (root->left == NULL and root->right == NULL) {
        if (maxLevel == 0) {
            maxLevel = level;
        }
        return level == maxLevel;
    }

    return (help(root->left, level + 1, maxLevel)) and (help(root->right, level + 1, maxLevel));
}
bool check(Node *root)
{
    int maxLevel = 0;
    return help(root, 0, maxLevel);
}