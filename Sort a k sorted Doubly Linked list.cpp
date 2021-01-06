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

struct compare {
	bool operator()(node *a, node *b) {
		return a->data > b->data;
	}
};


node *sortKsorted(node *head, int k) {

	priority_queue<node*, vector<node*>, compare> pq;

	for (int i = 0; i <= k and head != NULL; i++, head = head->next) {
		pq.push(head);
	}

	node *newHead = NULL;
	node *last = NULL;
	while (!pq.empty()) {
		node *t = pq.top();
		pq.pop();
		if (newHead == NULL) {
			newHead = t;
			newHead->prev = NULL;
			last = newHead;
		}
		else {
			last->next = t;
			t->prev = last;
			last = t;
		}
		if (head != NULL) {
			pq.push(head);
			head = head->next;
		}
	}

	last->next = NULL;
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
	node *ans = sortKsorted(head, x);

	display(ans);
	return 0;
}