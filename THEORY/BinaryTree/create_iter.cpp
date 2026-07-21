#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
Node *CreateBT()
{
    cout << "Value for Root Node: " << endl;
    int temp;
    cin >> temp;
    if (temp == -1)
    {
        return nullptr;
    }

    Node *p = new Node(temp);
    p->val = temp;
    queue<Node *> q;
    q.push(p); // Starting with the root node

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        cout << "Left Value for Node: " << curr->val << " : " << endl;
        int temp;
        cin >> temp;
        if (temp != -1)
        {
            Node *left = new Node(temp);
            curr->left = left;
            q.push(left);
        }

        cout << "Right Value for Node: " << curr->val << " : " << endl;
        cin >> temp;
        if (temp != -1)
        {
            Node *right = new Node(temp);
            curr->right = right;
            q.push(right);
        }
    }
    return p;
}

void Preorder(Node *p)
{
    if (p == nullptr)
        return;

    cout << p->val << " ";
    Preorder(p->left);
    Preorder(p->right);
}

void Inorder(Node *p)
{
    if (p == nullptr)
        return;

    Inorder(p->left);
    cout << p->val << " ";
    Inorder(p->right);
}

void Postorder(Node *p)
{
    if (p == nullptr)
        return;

    Postorder(p->left);
    Postorder(p->right);
    cout << p->val << " ";
}

int main()
{
    Node *root = CreateBT();
    cout << root << endl;

    cout << "Preorder\n";
    Preorder(root);
    cout << "\n";

    cout << "Inorder\n";
    Inorder(root);
    cout << "\n";

    cout << "Postorder\n";
    Postorder(root);
    cout << "\n";
    return 0;
}
