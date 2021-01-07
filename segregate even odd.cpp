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

node *segregate(node *head) {
	node *odd = NULL;
	node *even = NULL;
	node *evenHead = NULL;
	node *oddHead = NULL;
	node *temp = head;
	while (temp != NULL) {
		if (temp->data % 2 == 0) {
			if (even == NULL) {
				even = new node(temp->data);
				evenHead = even;
			}
			else {
				even->next = new node(temp->data);
				even = even->next;
			}
		}
		else {
			if (odd == NULL) {
				odd = new node(temp->data);
				oddHead = odd;
			}
			else {
				odd->next = new node(temp->data);
				odd = odd->next;
			}
		}
		temp = temp->next;
	}
	if (evenHead == NULL) {
		return oddHead;
	}
	even->next = oddHead;
	return evenHead;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		node *head = NULL;
		int n;
		cin >> n;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			insert(head, x);
		}

		head = segregate(head);
		display(head);
		cout << endl;
	}
	return 0;
}