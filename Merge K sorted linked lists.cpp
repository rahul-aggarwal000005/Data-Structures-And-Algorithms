
Node *merge(Node *a, Node *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	Node *c = NULL;
	if (a->data < b->data) {
		c = new Node(a->data);
		c->next = merge(a->next, b);
	}
	else {
		c = new Node(b->data);
		c->next = merge(a, b->next);
	}
	return c;
}

Node * mergeKLists(Node *arr[], int N)
{
	// {{1,2,3},{4 5},{5 6},{7,8}}
	if (N == 1) return arr[0];

	Node *first = arr[0];

	for (int i = 1; i < N; i++) {
		Node *second = arr[i];
		first = merge(first, second);
	}

	return first;

}