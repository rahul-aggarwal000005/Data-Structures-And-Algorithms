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

node *reverse(node *head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node *c = head;
	node *n = head;
	node *p = NULL;
	while (c != NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}

	return p;
}

node *addOne(node *head) {
	head = reverse(head);
	node *temp = head;
	node *prev = NULL;
	int carry = 1;
	while (temp != NULL) {
		int data = temp->data;
		int sum = data + carry;
		int val = sum % 10;
		carry = sum / 10;
		temp->data = val;
		prev = temp;
		temp = temp->next;
	}

	if (carry) {
		prev->next = new node(1);
	}
	temp = reverse(head);
	return temp;
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

	node *ans = addOne(head);

	display(ans);
	return 0;
}