void removeLoop(Node* head)
{
    if (head == NULL) return;
    bool found = false;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            found = true;
            break;
        }
    }

    if (!found) return;

    // if there is a cycle detect the interesection point
    fast = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }

    while (fast->next != slow) {
        fast = fast->next;
    }

    fast->next = NULL;
}