#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int val;
	node *next;
	node(int d) {
		val = d;
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
		cout << head->val << " ";
		head = head->next;
	}
}

node *reverseRec(node *head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}
	node *rec = reverseRec(head->next);
	head->next = NULL;
	node *ans = rec;
	while (ans->next != NULL) {
		ans = ans->next;
	}
	ans->next = head;
	return rec;
}

node *reverseIter(node *head) {
	if (head == NULL or head->next == NULL) return head;
	node *c = head;
	node *p = NULL;
	node *n = head;
	while (n != NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	return p;
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
	node *rev = reverseIter(head);
	display(rev);
	return 0;
}