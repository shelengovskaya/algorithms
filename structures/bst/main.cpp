#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    node * left, * right;
    node(int key)
    {
        x = key;
        left = nullptr;
        right = nullptr;
    }
    ~node()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool exists(node * root, int val)
{
    if (root == nullptr)
        return false;
    if (root->x == val)
        return true;
    if (val < root->x)
        return exists(root->left, val);
    else
        return exists(root->right, val);

}

node * insert (node * root, int val)
{
    if (exists(root, val))
        return root;
    if (root == nullptr)
        return new node(val);
    if (val < root->x)
        root->left = insert(root->left, val);
    if (val > root->x)
        root->right = insert(root->right, val);
    return root;
}

int depth (node * root)
{
    if (root == nullptr)
        return 0;
    return max(depth(root->right), depth(root->left)) + 1;
}

void print(node * root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        cout << root->x << endl;kl
    else
    {
        print(root->left);
        print(root->right);
    }
}


int main()
{
    int n;
    node * root = NULL;
    int i;
    cin >> i;
    while (i != 0)
    {
        root = insert(root, i);
        cin >> i;
    }
  //  cout << root->x;
   // print(root);
  //  cout << depth(root);
    print (root);
    return 0;
}
