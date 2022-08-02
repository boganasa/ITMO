#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

struct Node
{
    char meaning;
    Node *prev;
};

void push(Node *&top, char value)
{
    Node *ph = new Node;
    ph->meaning = value;
    ph->prev = top;
    top = ph;
}

long long pop(Node *&top, char value0)
{
    if (top == NULL)
    {
        return 0;
    }
    char value = top->meaning;
    Node *ph = top;
    top = top->prev;
    delete ph;
    if (value == value0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ifstream fcin("brackets.in");
    ofstream fout("brackets.out");

    string line;
    int rezult = 1;

    while (getline(fcin, line))
    {
        Node *top = NULL;
        rezult = 1;
        for (int i = 0; i < line.length(); i++)
        {
            if ((line[i] == '(') || (line[i] == '['))
            {
                push(top, line[i]);
            }
            else
            {
                if (line[i] == ')')
                {
                    rezult = pop(top, '(');
                }
                else
                {
                    rezult = pop(top, '[');
                }

                if (!rezult)
                {
                    break;
                }
            }
        }

        if ((rezult) && (top == NULL))
        {
            fout << "YES" << '\n';
        }
        else
        {
            fout << "NO" << '\n';
        }

        delete top;
    }
    fcin.close();
    fout.close();
    return 0;
}