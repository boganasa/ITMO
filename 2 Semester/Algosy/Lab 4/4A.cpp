#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Node
{
    long long meaning;
    Node *prev;
};

void push(Node *&top, long long value)
{
    Node *ph = new Node;
    ph->meaning = value;
    ph->prev = top;
    top = ph;
}

long long pop (Node *&top)
{
    long long value = top->meaning;
    Node* ph = top;
    top = top->prev;
    delete ph;
    return value;
}

int main()
{
    ifstream fcin("stack.in");
    ofstream fout ("stack.out");

    char operation;
    int M;
    long long value;

    Node *top = NULL;

    fcin >> M;

    for (int i = 0; i < M; i++)
    {
        fcin >> operation;
        if (operation == '+')
        {
            fcin >> value;
            push(top, value);
        }

        else if (operation == '-')
        {
            fout << pop(top) << endl;
        }
    }

    fcin.close();
    fout.close();
    return 0;
}