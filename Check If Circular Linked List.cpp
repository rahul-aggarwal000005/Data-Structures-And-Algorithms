bool isCircular(Node *head)
{
	// Your code here
	if (head->next == head) return true;
	Node *temp = head;
	do {
		temp = temp->next;
		if (temp == NULL) return false;

	} while (temp != head);
	return true;

}