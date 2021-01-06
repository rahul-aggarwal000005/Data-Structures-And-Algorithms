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
		head->next = head;
		return;
	}
	node *temp = head;

	do {
		temp = temp->next;
	} while (temp->next != head);

	temp->next = new node(d);
	temp = temp->next;
	temp->next = head;
}

void display(node *head) {
	node *temp = head;
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
}

void deleteNode(node *&head, int x) {
	if (head == NULL) {
		cout << "List is Empty";
		return;
	}
	if (head->next == head and head->data != x) {
		cout << "Element not present";
		return;
	}
	if (head->next == head and head->data == x) {
		head = NULL;
		return;
	}

	// check if the element is present or not
	node *temp = head;
	node *prev = NULL;
	bool found = false;
	do {
		if (temp->data == x) {
			found = true;
			break;
		}
		prev = temp;
		temp = temp->next;
	} while (temp != head);

	if (!found) {
		cout << "element not found";
		return;
	}

	// if the element is found check if it is at first index
	if (temp == head) {
		// move the temp to last node
		prev = NULL;
		do {
			prev = temp;
			temp = temp->next;
		} while (temp != head);
		head = head->next;
		prev->next = head;
		return;
	}
	// if the element found check if it is last node
	if (temp->next == head) {
		prev->next = head;
		return;
	}

	// else its an intermediate node
	prev->next = temp->next;
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

	cin >> x;
	deleteNode(head, x);
	display(head);

	return 0;
}