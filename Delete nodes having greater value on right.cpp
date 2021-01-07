
Node *reverse(Node *head) {
    if (head == NULL or head->next == NULL) return head;
    Node *cur = head;
    Node *prev = NULL;
    Node *n = head;
    while (cur != NULL) {
        n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }

    return prev;

}
Node *compute(Node *head)
{
    if (head == NULL or head->next == NULL) return head;
    // your code goes here
    head = reverse(head);
    Node *cur = head;
    Node *n = head->next;
    // 12->15->10->11->5->6->2->3
    // 3->2->6->5->11->10->15->12
    while (n != NULL) {
        if (cur->data > n->data) {
            n = n->next;
        }
        else {
            cur->next = n;
            cur = n;
            n = cur->next;
        }
    }
    cur->next = NULL;
    return reverse(head);
}