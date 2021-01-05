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

void moveLastToFirst(node *&head) {

	if (head == NULL or head->next == NULL) return;
	node *last = head->next->next;
	node *secondLast = head->next;
	while (last->next != NULL) {
		secondLast = secondLast->next;
		last = last->next;
	}

	secondLast->next = NULL;
	last->next = head;
	head = last;
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

	moveLastToFirst(head);

	display(head);
	return 0;
}