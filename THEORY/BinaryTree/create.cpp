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

Node *CreateBT(Node *root)
{
    if (root == nullptr)
    {
        cout << "val> ";
    }
    int temp;
    cin >> temp;
    cout << "\n";
    if (temp == -1)
    {
        return nullptr;
    }
    Node *curr = new Node(temp);
    cout << "Value for Left Node" << curr->val << endl;
    auto leftNode = CreateBT(curr->left);
    cout << "Value for Right Node: " << curr->val << endl;
    auto rightNode = CreateBT(curr->right);
    curr->left = leftNode;
    curr->right = rightNode;

    return curr;
}

void Preorder(Node *p)
{
    if (p == nullptr)
    {
        return;
    }

    cout << p->val << " ";
    Preorder(p->left);
    Preorder(p->right);
}

void Inorder(Node *p)
{
    if (p == nullptr)
    {
        return;
    }

    Inorder(p->left);
    cout << p->val << " ";
    Inorder(p->right);
}

void Postorder(Node *p)
{
    if (p == nullptr)
    {
        return;
    }

    Postorder(p->left);
    Postorder(p->right);
    cout << p->val << " ";
}

int main()
{
    Node *root = CreateBT(nullptr);
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
