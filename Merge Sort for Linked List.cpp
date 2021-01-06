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

node *middle(node *head) {
	if (head == NULL or head->next == NULL) return head;

	node *slow = head;
	node *fast = head->next;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node *merge(node *a, node *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;

	node *c = NULL;
	if (a->data < b->data) {
		c = new node(a->data);
		c->next = merge(a->next, b);
	}
	else {
		c = new node(b->data);
		c->next = merge(a, b->next);
	}
	return c;
}

node *mergeSort(node *head) {
	if (head == NULL or head->next == NULL) return head;

	// find the mid node
	node *mid = middle(head);
	node *b = mid->next;
	node *a = head;
	mid->next = NULL;
	a = mergeSort(a);
	b = mergeSort(b);
	node *c = merge(a, b);
	return c;
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
	node *ans = mergeSort(head);

	display(ans);
	return 0;
}