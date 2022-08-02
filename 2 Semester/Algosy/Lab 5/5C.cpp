#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

struct Node
{
    long long key;
    Node *left;
    Node *right;
    Node *parent;
};

Node *tree_insert(Node *&root, long long k)
{
    Node *ptr = root;
    if (!ptr)
    {
        Node *pnew = new Node;
        pnew->key = k;
        pnew->left = 0;
        pnew->right = 0;
        pnew->parent = 0;

        root = pnew;
        ptr = pnew;
    }
    else
    {
        int key_insert = 1;
        while (key_insert == 1)
        {
            if (k < ptr->key)
            {
                if (!ptr->left)
                {
                    Node *pnew = new Node;
                    pnew->key = k;
                    pnew->left = 0;
                    pnew->right = 0;
                    pnew->parent = ptr;
                    ptr->left = pnew;
                    ptr = pnew;
                    key_insert = 0;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            else if (k > ptr->key)
            {
                if (!ptr->right)
                {
                    Node *pnew = new Node;
                    pnew->key = k;
                    pnew->left = 0;
                    pnew->right = 0;
                    pnew->parent = ptr;
                    ptr->right = pnew;
                    ptr = pnew;
                    key_insert = 0;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            else
            {
                key_insert = 0;
            }
        }
    }
    return ptr;
}

long long tree_delete(Node *&root, long long k)
{
    Node *ptr = root;
    Node *prev = 0;
    int key_find = 0;
    while ((ptr) && (!key_find))
    {
        if (k < ptr->key)
        {
            prev = ptr;
            ptr = ptr->left;
        }
        else if (k > ptr->key)
        {
            prev = ptr;
            ptr = ptr->right;
        }
        else
        {
            key_find = 1;
        }
    }
    if (!ptr)
    {
        return 0;
    }
    if (!ptr->right) // У узла, который удалаем нет правого поддерева
    {
        if (prev)
        {
            if (k < prev->key)
            {
                prev->left = ptr->left;
            }
            else
            {
                prev->right = ptr->left;
            }
        }
        else
        {
            root = ptr->left;
        }
        delete ptr;
    }
    else if ((ptr->right) && (!ptr->right->left)) //У правого сына, узла который удалаем, нет левого поддерева
    {
        ptr->right->left = ptr->left;
        if (prev)
        {
            if (k < prev->key)
            {
                prev->left = ptr->right;
            }
            else
            {
                prev->right = ptr->right;
            }
        }
        else
        {
            root = ptr->right;
        }
        delete ptr;
    }
    else
    {
        Node *ptr1 = ptr->right;
        Node *ptr2 = ptr;
        while (ptr1->left)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->left;
        }
        ptr2->left = ptr1->right;
        ptr->key = ptr1->key;
        delete ptr1;
    }
    return 0;
}

int tree_exists(Node *&root, long long k)
{
    Node *ptr = root;
    int key_exists = 0;
    while ((ptr) && (!key_exists))
    {
        if (k > ptr->key)
        {
            ptr = ptr->right;
        }
        else if (k < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            key_exists = 1;
        }
    }
    return key_exists;
}

Node *tree_min(Node *x)
{
    while (x->left)
    {
        x = x->left;
    }
    return x;
}

Node *tree_max(Node *x)
{
    while (x->right)
    {
        x = x->right;
    }
    return x;
}

Node *tree_next(Node *&root, long long k)
{
    Node *ptr = root;
    Node *prev = 0;
    while (ptr)
    {
        if (ptr->key > k)
        {
            prev = ptr;
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return prev;
}

Node *tree_prev(Node *&root, long long k)
{
    Node *ptr = root;
    Node *prev = 0;
    while (ptr)
    {
        if (ptr->key < k)
        {
            prev = ptr;
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }
    return prev;
}

int main()
{
    ifstream fcin("bstsimple.in");
    ofstream fout("bstsimple.out");
    char str[10];
    long long k;
    Node *root = 0;

    while (!fcin.eof())
    {
        fcin >> str >> k;
        if (strcmp(str, "insert") == 0)
        {
            *tree_insert(root, k);
        }
        else if (strcmp(str, "delete") == 0)
        {
            tree_delete(root, k);
        }
        else if (strcmp(str, "exists") == 0)
        {
            int rezult_exists = tree_exists(root, k);
            if (rezult_exists == 1)
            {
                fout << "true";
                if (!fcin.eof())
                {
                    fout << '\n';
                }
            }
            else
            {
                fout << "false";
                if (!fcin.eof())
                {
                    fout << '\n';
                }
            }
        }
        else if (strcmp(str, "next") == 0)
        {
            Node *rezult_next = tree_next(root, k);
            if (rezult_next == 0)
            {
                fout << "none";
                if (!fcin.eof())
                {
                    fout << '\n';
                }
            }
            else
            {
                fout << rezult_next->key;
                if (!fcin.eof())
                {
                    fout << '\n';
                }
            }
        }
        else if (strcmp(str, "prev") == 0)
        {
            Node *rezult_prev = tree_prev(root, k);
            if (rezult_prev == 0)
            {
                fout << "none";
                if (!fcin.eof())
                {
                    fout << '\n';
                }
            }
            else
            {
                fout << rezult_prev->key;
                if (!fcin.eof())
                {
                    fout << '\n';
                }
            }
        }
        str[0] = '1';
    }

    fcin.close();
    fout.close();
    return 0;
}