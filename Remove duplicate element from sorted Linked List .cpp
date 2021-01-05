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

node *removeDuplicates(node *head) {

	if (head == NULL or head->next == NULL) return head;

	node *temp = head;
	while (temp != NULL and temp->next != NULL) {
		node *cur = temp;
		node *Next = temp->next;
		if (cur->data == Next->data) {
			node *x = Next;
			while (x != NULL and x->data == cur->data) {
				x = x->next;
			}
			temp->next = x;
		}
		temp = temp->next;
	}
	return head;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	int x;
	node *head = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(head, x);
	}

	node *ans = removeDuplicates(head);

	display(ans);
	return 0;
}