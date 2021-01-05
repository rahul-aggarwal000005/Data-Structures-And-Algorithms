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

node *addTwoLists(node *first, node *second) {
	first = reverse(first);
	second = reverse(second);
	node *result = NULL;
	node *tail = NULL;
	int d1 = 0, d2 = 0, sum = 0, v, carry = 0;
	while (first != NULL and second != NULL) {
		d1 = first->data;
		d2 = second->data;
		sum = (d1 + d2 + carry);
		v = sum % 10;
		carry = sum / 10;
		if (tail == NULL) {
			tail = new node(v);
			result = tail;
		}
		else {
			node *n = new node(v);
			tail->next = n;
			tail = tail->next;
		}
		first = first->next;
		second = second->next;
	}

	while (first != NULL) {
		d1 = first->data;
		sum = (d1 + carry);
		v = sum % 10;
		carry = sum / 10;
		node *n = new node(v);
		tail->next = n;
		tail = tail->next;
		first = first->next;
	}
	while (second != NULL) {
		d2 = second->data;
		sum = (d2 + carry);
		v = sum % 10;
		carry = sum / 10;
		node *n = new node(v);
		tail->next = n;
		tail = tail->next;
		second = second->next;
	}

	if (carry) {
		node *n = new node(1);
		tail->next = n;
	}
	result = reverse(result);
	return result;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int x;
	node *first = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(first, x);
	}
	int m;
	cin >> m;
	node *second = NULL;
	for (int i = 0; i < m; i++) {
		cin >> x;
		insert(second, x);
	}

	node *ans = addTwoLists(first, second);

	display(ans);
	return 0;
}