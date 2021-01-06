#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;
	node *prev;
	node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
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
	temp->next->prev = temp;
}

void display(node *head) {
	node *temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

}

node *reverse(node *head) {
	if (head == NULL or head->next == NULL) return head;

	node *cur = head;
	node *n = head;
	while (cur->next != NULL) {
		n = cur->next;
		cur->next = cur->prev;
		cur->prev = n;
		cur = n;
	}
	cur->next = cur->prev;
	cur->prev = NULL;
	return cur;
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

	node *rev = reverse(head);
	display(rev);
	return 0;
}