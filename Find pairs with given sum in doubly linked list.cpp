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

void findPair(node *head, int x) {
	if (head == NULL or head->next == NULL) {
		cout << "Not found";
		return;
	}

	// use two pointer first pointer points to first and second will point toend
	node *last = head;
	while (last->next != NULL) {
		last = last->next;
	}

	node *first = head;
	bool found = false;
	while (first != NULL and last != NULL and first != last and last->next != first) {
		int sum = first->data + last->data;
		if (sum == x) {
			found = true;
			cout << first->data << " " << last->data << endl;
			first = first->next;
			last = last->prev;
		}
		else if (sum < x) {
			first = first->next;
		}
		else {
			last = last->prev;
		}
	}

	if (!found) {
		cout << "No pair Found";
	}
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
	findPair(head, x);

	return 0;
}