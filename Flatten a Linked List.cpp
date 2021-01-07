
Node *merge(Node *a, Node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node *c = NULL;
    if (a->data < b->data) {
        c = new Node(a->data);
        c->bottom = merge(a->bottom, b);
    }
    else {
        c = new Node(b->data);
        c->bottom = merge(a, b->bottom);
    }
    return c;
}
Node *flatten(Node *root)
{
    if (root == NULL or root->next == NULL) return root;

    /*
        5 -> 10 -> 19 -> 28
        |     |     |     |
        7     20    22   35
        |           |     |
        8          50    40
        |                 |
        30               45

    */
    Node *first = root;
    Node *second = root->next;

    while (second != NULL) {
        first = merge(first, second);
        second = second->next;
    }
    return first;

}

