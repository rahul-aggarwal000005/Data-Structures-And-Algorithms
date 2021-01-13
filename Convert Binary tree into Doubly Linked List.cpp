
void convert(node *&head, node *root) {
    if (root == NULL) return;

    static node *prev = NULL;
    convert(head, root->left);
    if (head == NULL) {
        head = root;
    }
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convert(head, root->right);
}

Node * bToDLL(Node *root)
{
    Node *head = NULL;
    convert(head, root);
    return head;
}