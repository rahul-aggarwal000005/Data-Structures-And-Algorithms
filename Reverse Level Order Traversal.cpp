
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *t = q.front();
        q.pop();
        res.push_back(t->data);
        if (t->right) {
            q.push(t->right);
        }
        if (t->left) {
            q.push(t->left);
        }
    }

    reverse(res.begin(), res.end());
    return res;
}