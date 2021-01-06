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

node *rotateK(node *head, int k) {
	node *newHead = head;
	int i;
	for (i = 0; i < k and newHead != NULL; i++) {
		newHead = newHead->next;
	}

	if (i != k) return head;

	node *newTail = newHead->prev;
	newTail->next = NULL;

	node *tail = newHead;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = head;
	head->prev = tail;

	return newHead;
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
	node *ans = rotateK(head, x);

	display(ans);
	return 0;
}