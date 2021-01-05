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


node *reverse(node *head, int k) {
	if (head == NULL) return head;
	node *temp = head;
	node *prev = NULL;
	int cnt = 0;
	while (temp != NULL and cnt < k) {
		cnt++;
		prev = temp;
		temp = temp->next;
	}


	node *rec = reverse(temp, k);
	prev->next = NULL;
	node *c = head;
	node *n = head;
	node *p = NULL;
	while (c != NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}

	head->next = rec;
	return prev;
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

	node *rev = reverse(head, k);
	display(rev);
	return 0;
}