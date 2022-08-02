#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

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

long long pop(Node *&top, char operation)
{
    long long value1 = top->meaning;
    Node *ph1 = top;
    top = top->prev;
    delete ph1;
    long long value2 = top->meaning;
    Node *ph2 = top;
    top = top->prev;
    delete ph2;

    long long value3;
    if (operation == '-')
    {
        value3 = value2 - value1;
    }
    else if (operation == '+')
    {
        value3 = value1 + value2;
    }
    else
    {
        value3 = value1 * value2;
    }

    push(top, value3);
    return value3;
}

int main()
{
    ifstream fcin("postfix.in");
    ofstream fout("postfix.out");

    string str;
    long long result = 0;
    long long value;

    Node *top = NULL;

    while (fcin >> str)
    {

        if ((str[0] != '+') && (str[0] != '-') && (str[0] != '*'))
        {
            value = 0;
            for (int i = 0; i < str.length(); i++)
            {
                value = value * 10 + ((long long)(str[i] - '0'));
            }
            push(top, value);
        }

        else
        {
            result = pop(top, str[0]);
        }
    }
    fout << result;
    fcin.close();
    fout.close();
    return 0;
}