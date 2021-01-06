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

int getLength(node *head) {
	int cnt = 0;
	while (head != NULL) {
		head = head->next;
		cnt++;
	}
	return cnt;
}

node *reverse(node *head) {
	node *cur = head;
	node *n = head;
	node *prev = NULL;
	while (cur != NULL) {
		n = cur->next;
		cur->next = prev;
		prev = cur;
		cur = n;
	}
	return prev;
}
bool isPalindrome(node *head) {
	int l = getLength(head);
	node *temp = head;
	int l1 = l % 2 == 0 ? l / 2 : l / 2 + 1;
	for (int i = 0; i < l1; i++) {
		temp = temp->next;
	}
	node *x = reverse(temp);
	temp = head;
	while (x != NULL) {
		if (x->data != temp->data) {
			return false;
		}
		x = x->next;
		temp = temp->next;
	}
	return true;
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
	// display(head);
	if (isPalindrome(head)) {
		cout << "yes";
	} else {
		cout << "No";
	}

	return 0;
}