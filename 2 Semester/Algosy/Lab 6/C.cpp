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
    Node *put_next;
    Node *put_prev;
};

Node *adres = NULL;

void add(Node *&ptr, string flag, string data)
{
    Node *ph = new Node;
    ph->key = flag;
    ph->meaning = data;
    ph->put_prev = adres;
    ph->put_next = NULL;
    if (adres != NULL)
    {
        adres->put_next = ph;
    }
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
    adres = ph;
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
    Node *cur0 = cur;
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

    if ((cur0->put_next != NULL) && (cur0->put_prev != NULL))
    {
        cur0->put_next->put_prev = cur0->put_prev;
        cur0->put_prev->put_next = cur0->put_next;
    }
    else if ((cur0->put_next == NULL) && (cur0->put_prev != NULL))
    {
        cur0->put_prev->put_next = NULL;
        adres = cur0->put_prev;
    }
    else if ((cur0->put_next != NULL) && (cur0->put_prev == NULL))
    {
        cur0->put_next->put_prev = NULL;
    }
    else
    {
        adres = NULL;
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
    ifstream fcin("linkedmap.in");
    ofstream fout("linkedmap.out");

    Node *arr[1490];
    int odds = 1489;

    for (int i = 0; i < odds; i++)
    {
        arr[i] = NULL;
    }

    char data[22];
    char flag[22];
    char command[10];
    long long index;
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
        index = abs(odds_index % odds);

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

        else if (strcmp(command, "prev") == 0)
        {
            Node *cur = get(arr[index], flag);
            if (cur == NULL)
            {
                fout << "none" << endl;
            }
            else if (cur->put_prev != NULL)
            {
                fout << cur->put_prev->meaning << endl;
            }
            else
            {
                fout << "none" << endl;
            }
        }

        else if (strcmp(command, "next") == 0)
        {
            Node *cur = get(arr[index], flag);
            if (cur == NULL)
            {
                fout << "none" << endl;
            }
            else if (cur->put_next != NULL)
            {
                fout << cur->put_next->meaning << endl;
            }
            else
            {
                fout << "none" << endl;
            }
        }
        command[0] = '\0';
    }
    fcin.close();
    fout.close();
    return 0;
}