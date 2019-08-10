#include <iostream>

using namespace std;

struct node
{
    int x;
    int y;
    node * left;
    node * right;

    node (int val, int diff)
    {
        x = val;
        y = diff;
        left = nullptr;
        right = nullptr;
    }

    ~node ()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

/*bool exists (node * root, int key)
{
    if (root == nullptr)
        return false;
    if (key == root->x)
        return true;
    if (key > root->x)
        return exists(root->right, key);
    return exists(root->left, key);
}*/

pair <node *, node *> split (node * root, int val)
{
    if (root == nullptr)
        return {nullptr, nullptr};
    if (val >= root->x)
        {
            auto res = split(root->right, val);
            root->right = res.first;
            return {root, res.second};
        }
    else
    {
        auto res =  split(root->left, val);
        root->left = res.second;
        return {res.first, root};
    }
}

node * merge(node * root1, node * root2)
{
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    if (root1->y <= root2->y)
    {
        root1->right = merge(root1->right, root2);
        return root1;
    }
    else
    {
        root2->left = merge(root1, root2->left);
        return root2;
    }
}

node * insert (node * root, int val, int diff)
{
//    if (exists(root, val))
  //      return root;
    auto res = split(root, val);
    node * newnode = new node(val, diff);
    return merge(merge(res.first, newnode), res.second);
}

/*node * erase (node * root, int val)
{
    if (!exists(root, val))
        return root;
    auto res1 = split(root, val);
    auto res2 = split(res1.first, val - 1);
    delete res2.second;
    return merge(res2.first, res1.second);
}*/

void print (node * root)
{
    if (root == nullptr)
        return;
    cout << root->x << " ";
    print(root->left);
    print(root->right);
}

int depth(node * root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(depth(root->right), depth(root->left));
}

int main()
{
  //  node * root = nullptr;
    int r = 1;
    int i = 2;
    while (i != 0)
    {
        cin >> i;
        root = insert(root, i, r);
        r++;
    }

  //  for (int i = 0; i < 50; i += 2)
   //     root = erase(root, i);
   // print(root);
    cout << depth(root);
    return 0;
}
