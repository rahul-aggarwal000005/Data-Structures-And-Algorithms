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


node *findIntersection(node *head1, node *head2) {
	node *first = head1;
	node *second = head2;
	node *result = NULL;
	node *tail = NULL;
	while (head1 != NULL and head2 != NULL) {
		int d1 = head1->data;
		int d2 = head2->data;
		if (d1 == d2) {
			if (result == NULL) {
				result = new node(d1);
				tail = result;
			}
			else {
				node *n = new node(d1);
				tail->next = n;
				tail = tail->next;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
		else if (d1 < d2) {
			head1 = head1->next;
		}
		else {
			head2 = head2->next;
		}
	}
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
	node *head1 = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(head1, x);
	}
	int m;
	cin >> m;
	node *head2 = NULL;
	for (int i = 0; i < m; i++) {
		cin >> x;
		insert(head2, x);
	}

	node *ans = findIntersection(head1, head2);

	display(ans);
	return 0;
}