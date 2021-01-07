
class Pair {
public:
    int h;
    int d;
};

Pair Helper(Node *root) {
    Pair p;
    if (root == NULL) {
        p.h = 0;
        p.d = 0;
        return p;
    }

    Pair lst = Helper(root->left);
    Pair rst = Helper(root->right);

    int op1 = lst.d;
    int op2 = rst.d;
    int lh = lst.h;
    int rh = rst.h;
    int op3 = lh + rh + 1;
    p.h = max(lh, rh) + 1;
    p.d = max(op1, max(op2, op3));
    return p;
}

int diameter(Node* root) {
    // Your code here
    Pair ans = Helper(root);
    return ans.d;
}
