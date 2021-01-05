bool detectLoop(Node* head)
{
	// your code here
	if (head == NULL) return false;
	if (head->next == head) return true;

	Node *slow = head;
	Node *fast = head;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;;
		}
	}
	return false;
}
