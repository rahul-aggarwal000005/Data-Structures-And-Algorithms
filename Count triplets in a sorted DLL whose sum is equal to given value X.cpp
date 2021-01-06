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

int countPair(node *first, node *last, int x) {
	int count = 0;

	while (first != NULL and last != NULL and first != last and last->next != first) {
		int sum = first->data + last->data;
		if (sum == x) {
			count++;
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
	return count;
}

int countTriplet(node *head, int x) {
	int count = 0;
	node *cur = head;
	node *last = head;
	while (last->next != NULL) last = last->next;
	while (cur != NULL) {
		int m = countPair(cur->next, last, x - (cur->data));
		count += m;
		cur = cur->next;
	}
	return count;
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
	int ans = countTriplet(head, x);
	cout << ans << endl;
	return 0;
}