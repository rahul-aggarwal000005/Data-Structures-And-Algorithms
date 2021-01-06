#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insert(node *&head, int d) {
	if (head == NULL) {
		head = new node(d);
		return;
	}
	node *temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new node(d);
}

void display(node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

node *getTail(node *head) {
	if (head == NULL or head->next == NULL) return head;

	node *tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}

node *partition(node *head, node *tail, node **newHead, node **newTail) {
	node *pivot = tail;
	node *cur = head;
	node *end = tail;
	node *prev = NULL;
	while (cur != pivot) {
		if (cur->data < pivot->data) {
			if (*newHead == NULL) {
				*newHead = cur;
			}
			prev = cur;
			cur = cur->next;
		} else {
			if (prev) {
				prev->next = cur->next;
			}
			node *x = cur->next;
			cur->next = NULL;
			end->next = cur;
			end = cur;
			cur = x;
		}
	}

	// if the pivot is the smallest one
	if (*newHead == NULL) {
		*newHead = pivot;
	}
	*newTail = end;

	return pivot;
}

node *quickSortHelper(node *head, node *tail) {
	// if 0 or 1 element is present in the list
	if (head == NULL or head == tail) return head;

	// put the end element at its correct position using partition function
	node *newHead = NULL;
	node *newTail = NULL;
	node *pivot = partition(head, tail, &newHead, &newTail);

	// if the pivot is not the smallest element
	if (newHead != pivot) {
		// sort the first part of the list before pivot
		node *temp = newHead;
		while (temp->next != pivot) {
			temp = temp->next;
		}
		temp->next = NULL;
		newHead = quickSortHelper(newHead, temp);
		temp = getTail(newHead);
		temp->next = pivot;
	}

	pivot->next = quickSortHelper(pivot->next, newTail);
	return newHead;
}

void quickSort(node **head) {
	*head = quickSortHelper(*head, getTail(*head));
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int x;
	node *head = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(head, x);
	}
	// display(head);
	quickSort(&head);

	display(head);
	return 0;
}