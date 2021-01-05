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
	node *cur = head;
	node *prev = NULL;
	unordered_set<int> s;
	while (cur != NULL) {
		int d = cur->data;
		if (s.find(d) == s.end()) {
			s.insert(d);
			prev = cur;
			cur = cur->next;
		}
		else {
			prev->next = cur->next;
			cur = cur->next;
		}
	}



	return head;
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

	node *ans = removeDuplicates(head);

	display(ans);
	return 0;
}