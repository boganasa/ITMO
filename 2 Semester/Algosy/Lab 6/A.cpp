#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Node
{
    long long key;
    Node *next;
    Node *prev;
};

void add(Node *&ptr, long long data)
{
    Node *ph = new Node;
    ph->key = data;
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

void del(Node *&ptr, long long data)
{
    Node *cur = ptr;
    while ((cur != NULL) && (data != cur->key))
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

bool exists(Node *&ptr, long long data)
{
    Node *cur = ptr;
    while (cur != NULL)
    {
        if (cur->key == data)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int main()
{
    ifstream fcin("set.in");
    ofstream fout("set.out");

    Node *arr[9973];
    int odds = 9973;
    for (int i = 0; i < odds; i++)
    {
        arr[i] = NULL;
    }

    string command;
    long long data;
    int index;

    while (getline(fcin, command))
    {
        data = 0;
        for (int i = 7; i < command.length(); i++)
        {
            data = data * 10 + (int)(command[i] - '0');
        }

        index = abs(data % odds);

        if (command[0] == 'i')
        {
            if (!exists(arr[index], data))
            {
                add(arr[index], data);
            }
        }

        else if (command[0] == 'd')
        {
            del(arr[index], data);
        }

        else if (command[0] == 'e')
        {
            bool answer = exists(arr[index], data);
            if (answer)
            {
                fout << "true" << endl;
            }
            else
            {
                fout << "false" << endl;
            }
        }
    }
    fcin.close();
    fout.close();
    return 0;
}