#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Node
{
    string meaning;
    string key;
    Node *next;
    Node *prev;
};

void add(Node *&ptr, string flag, string data)
{
    Node *ph = new Node;
    ph->key = flag;
    ph->meaning = data;
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
    ifstream fcin("map.in");
    ofstream fout("map.out");

    Node *arr[997];
    int odds = 997;

    for (int i = 0; i < odds; i++)
    {
        arr[i] = NULL;
    }

    string line;
    char data[22];
    char flag[22];
    char command[10];
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
            }
            else
            {
                cur->meaning = data;
            }
        }

        else if (strcmp(command, "delete") == 0)
        {
            del(arr[index], flag);
        }

        else if (strcmp(command, "get") == 0)
        {
            Node *cur = get(arr[index], flag);
            if (cur == NULL)
            {
                fout << "none" << endl;
            }
            else
            {
                fout << cur->meaning << endl;
            }
        }
        command[0] = '\0';
    }
    fcin.close();
    fout.close();
    return 0;
}