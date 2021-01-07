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

int length(node *head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

int getNthFromLast(node *head, int n) {

	node *fast = head;
	int i = 0;
	for (i = 0; i < n and fast != NULL; i++) {
		fast = fast->next;
	}

	if (i == n) {
		node *slow = head;
		while (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}

		return slow->data;
	}
	return -1;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *head = NULL;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(head, x);
	}

	cin >> x;
	int Nthnode = getNthFromLast(head, x);
	cout << Nthnode << " ";

	return 0;
}