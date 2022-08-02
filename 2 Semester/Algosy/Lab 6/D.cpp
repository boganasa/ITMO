#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Tree
{
    string key;
    Tree *left;
    Tree *right;
    Tree *parent;
};

struct Node
{
    Tree *root;
    string key;
    Node *next;
    Node *prev;
    int size;
};

Tree *tree_insert(Tree *&root, string k)
{
    Tree *ptr = root;
    if (!ptr)
    {
        Tree *pnew = new Tree;
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
                    Tree *pnew = new Tree;
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
                    Tree *pnew = new Tree;
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

long long tree_delete(Tree *&root, string k)
{
    Tree *ptr = root;
    Tree *prev = 0;
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
        Tree *ptr1 = ptr->right;
        Tree *ptr2 = ptr;
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

int tree_exists(Tree *&root, string k)
{
    Tree *ptr = root;
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
        else if (k == ptr->key)
        {
            key_exists = 1;
        }
    }
    return key_exists;
}

void tree_printf(Tree *root, std::ofstream &fout)
{
    fout << root->key << " ";
    if (root->left != NULL)
    {
        tree_printf(root->left, fout);
    }
    if (root->right != NULL)
    {
        tree_printf(root->right, fout);
    }
}

void add(Node *&ptr, string flag, string data)
{
    Node *ph = new Node;
    ph->key = flag;
    ph->root = NULL;

    Tree *tree_ptr = ph->root;
    Tree *pnew = new Tree;
    pnew->key = data;
    pnew->left = 0;
    pnew->right = 0;
    pnew->parent = 0;

    ph->root = pnew;
    tree_ptr = pnew;

    if (ptr == NULL)
    {
        ph->next = NULL;
        ph->prev = NULL;
        ptr = ph;
    }
    else
    {
        ph->prev = NULL;
        ph->next = ptr;
        ptr->prev = ph;
        ptr = ph;
    }
}

void del(Node *&ptr, string flag)
{
    Node *cur = ptr;
    while ((cur != NULL) && (flag != cur->key))
    {
        cur = cur->next;
    }
    if (cur == NULL)
    {
        return;
    }
    Node *delet = cur;
    cur->size = 0;
    if ((cur->next != NULL) && (cur->prev != NULL))
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    else if ((cur->next == NULL) && (cur->prev == NULL))
    {
        ptr = NULL;
    }

    else if (cur->prev == NULL)
    {
        cur->next->prev = NULL;
        ptr = cur->next;
    }

    else if (cur->next == NULL)
    {
        cur->prev->next = NULL;
    }

    delete delet;
}

Node *get(Node *&ptr, string flag)
{
    Node *cur = ptr;
    while (cur != NULL)
    {
        if (cur->key == flag)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int main()
{
    ifstream fcin("multimap.in");
    ofstream fout("multimap.out");

    Node *arr[997];
    int odds = 997;

    for (int i = 0; i < odds; i++)
    {
        arr[i] = NULL;
    }

    string line;
    char data[22];
    char flag[22];
    char command[12];
    int index;
    long long odds_index;

    while (!fcin.eof())
    {
        fcin >> command >> flag;

        if (command[0] == '\0')
        {
            continue;
        }

        odds_index = 0;
        for (int i = 0; i < strlen(flag); i++)
        {
            odds_index = odds_index + (int)(flag[i]) * i;
        }

        index = odds_index % odds;

        if (strcmp(command, "put") == 0)
        {
            fcin >> data;
            Node *cur = get(arr[index], flag);
            if (cur == NULL)
            {
                add(arr[index], flag, data);
                arr[index]->size = 1;
            }
            else
            {
                if (!tree_exists(cur->root, data))
                {
                    cur->size++;
                }
                tree_insert(cur->root, data);
            }
        }

        else if (strcmp(command, "delete") == 0)
        {
            fcin >> data;
            Node *cur = get(arr[index], flag);
            if ((cur != NULL) && (tree_exists(cur->root, data)))
            {
                cur->size--;
                tree_delete(cur->root, data);
                if (cur->size == 0)
                {
                    del(arr[index], flag);
                }
            }
        }

        else if (strcmp(command, "deleteall") == 0)
        {
            del(arr[index], flag);
        }

        else if (strcmp(command, "get") == 0)
        {
            Node *cur = get(arr[index], flag);
            if (cur == NULL)
            {
                fout << 0;
            }
            else
            {
                fout << cur->size << " ";
                tree_printf(cur->root, fout);
            }
            fout << endl;
        }
        command[0] = '\0';
    }
    fcin.close();
    fout.close();
    return 0;
}