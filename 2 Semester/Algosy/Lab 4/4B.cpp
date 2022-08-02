#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Node
{
    long long meaning;
    Node *prev;
};

void push(Node *&pbeg, Node *&pend, long long value)
{
    Node *ph = new Node;
    ph->meaning = value;
    ph->prev = NULL;
    if (pend)
    {
        pend->prev = ph;
    }
    else
    {
        pbeg = ph;
    }
    pend = ph;
}

long long pop (Node *&pbeg, Node *&pend)
{
    long long value = pbeg->meaning;
    Node* ph = pbeg;
    pbeg = pbeg->prev;
    if(!pbeg)
    {
        pend = NULL;
    }
    delete ph;
    return value;
}

int main()
{
    ifstream fcin("queue.in");
    ofstream fout ("queue.out");

    char operation;
    int M;
    long long value;

    Node *pbeg = NULL;
    Node *pend = NULL;

    fcin >> M;

    for (int i = 0; i < M; i++)
    {
        fcin >> operation;
        if (operation == '+')
        {
            fcin >> value;
            push(pbeg, pend, value);
        }

        else if (operation == '-')
        {
            fout << pop(pbeg, pend) << endl;
        }
    }

    fcin.close();
    fout.close();
    return 0;
}