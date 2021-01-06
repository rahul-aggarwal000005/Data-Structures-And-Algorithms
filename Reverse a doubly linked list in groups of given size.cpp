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

	node *n = head;
	node *cur = head;
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

node *reverseK(node *head, int k) {
	if (head == NULL) return head;

	int i = 0;
	node *newHead = head;
	while (i < k and head != NULL) {
		head = head->next;
		i++;
	}
	newHead = reverse(newHead);
	if (head != NULL) {
		head->prev->next = NULL;
		node *rec = reverseK(head, k);
		head = newHead;
		while (head->next != NULL) {
			head = head->next;
		}
		head->next = rec;
		rec->prev = head;
	}

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
	node *ans = reverseK(head, x);

	display(ans);
	return 0;
}