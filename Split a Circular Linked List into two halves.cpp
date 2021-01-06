int getLength(Node *head) {
    int cnt = 0;
    Node *temp = head;
    do {
        cnt++;
        temp = temp->next;
    } while (temp != head);
    return cnt;
}

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // find the length of the CLL
    if (head->next == head) {
        *head1_ref = head;
        return;
    }
    int l = getLength(head);
    int l1 = l % 2 == 0 ? l / 2 : l / 2 + 1;
    int l2 = l - l1;
    *head1_ref = head;
    Node *prev = NULL;
    for (int i = 0; i < l1; i++) {
        prev = head;
        head = head->next;
    }

    prev->next = *head1_ref;
    *head2_ref = head;
    for (int i = 0; i < l2; i++) {
        prev = head;
        head = head->next;
    }

    prev->next = *head2_ref;

}