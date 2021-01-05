int intersectPoint(Node* head1, Node* head2)
{
    int d1 = 0;
    int d2 = 0;
    Node *temp = head1;
    while (temp != NULL) {
        temp = temp->next;
        d1++;
    }
    temp = head2;
    while (temp != NULL) {
        temp = temp->next;
        d2++;
    }

    int diff = abs(d1 - d2);
    if (d1 > d2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    }
    else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }

    while (head1 != NULL and head2 != NULL) {
        if (head1 == head2) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;


}
