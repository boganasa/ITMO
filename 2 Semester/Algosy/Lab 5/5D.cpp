#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    long long meaning;
    Node *prev;
};

struct Label
{
    int index;
    string name;
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

long long pop(Node *&pbeg, Node *&pend)
{
    long long value = pbeg->meaning;
    Node *ph = pbeg;
    pbeg = pbeg->prev;
    if (!pbeg)
    {
        pend = NULL;
    }
    delete ph;
    return value;
}

int labelFind(string *command, Label *label, int i, int n, int index)
{
    string label0 = command[i].substr(index, command[i].length());
    for (int j = 0; j < n; j++)
    {
        if (label[j].name == label0)
        {
            return label[j].index;
        }
    }
    return 0;
}

int main()
{
    ifstream fcin("quack.in");
    ofstream fout("quack.out");

    Node *pbeg = NULL;
    Node *pend = NULL;
    string str;
    string *command = new string[10000000];
    int value1 = 0, value2 = 0, n = 0, i = 0, n_label = 0;
    int regis[26];
    Label *label = new Label[1000];
    for (int i = 0; i < 26; i++)
    {
        regis[i] = 0;
    }

    while (!fcin.eof())
    {
        getline(fcin, command[i]);
        if (command[i][0] == ':')
        {
            label[n_label].index = i;
            label[n_label].name = command[i].substr(1, command[i].length());
            n_label++;
        }
        if (command[i][0] == '\0')
        {
            i--;
        }
        i++;
    }

    n = i;
    i = 0;

    while (i < n)
    {
        if (((int)(command[i][0] - '0') >= 0) && ((int)(command[i][0] - '0') <= 9))
        {
            value1 = 0;
            for (int j = 0; j < command[i].length(); j++)
            {
                value1 = value1 * 10 + (int)(command[i][j] - '0');
            }
            push(pbeg, pend, value1);
            i++;
        }

        else if (command[i][0] == '+')
        {
            value1 = pop(pbeg, pend);
            value2 = pop(pbeg, pend);
            push(pbeg, pend, (value1 + value2) & 65535);
            i++;
        }

        else if (command[i][0] == '-')
        {
            value1 = pop(pbeg, pend);
            value2 = pop(pbeg, pend);
            push(pbeg, pend, (value1 - value2) & 65535);
            i++;
        }

        else if (command[i][0] == '*')
        {
            value1 = pop(pbeg, pend);
            value2 = pop(pbeg, pend);
            push(pbeg, pend, value1 * value2 & 65535);
            i++;
        }

        else if (command[i][0] == '/')
        {
            value1 = pop(pbeg, pend);
            value2 = pop(pbeg, pend);
            if (value2 == 0)
            {
                push(pbeg, pend, 0);
            }
            else
            {
                push(pbeg, pend, value1 / value2 & 65535);
            }
            i++;
        }

        else if (command[i][0] == '%')
        {
            value1 = pop(pbeg, pend);
            value2 = pop(pbeg, pend);
            if (value2 == 0)
            {
                push(pbeg, pend, 0);
            }
            else
            {
                push(pbeg, pend, value1 % value2 & 65535);
            }
            i++;
        }

        else if (command[i][0] == '>')
        {
            value1 = pop(pbeg, pend);
            regis[(int)(command[i][1] - 'a')] = value1;
            i++;
        }

        else if (command[i][0] == '<')
        {
            push(pbeg, pend, regis[(int)(command[i][1] - 'a')]);
            i++;
        }

        else if ((command[i][0] == 'P') && (command[i].length() == 1))
        {
            value1 = pop(pbeg, pend);
            fout << value1 << '\n';
            i++;
        }
        else if (command[i][0] == 'P')
        {
            value1 = regis[(int)(command[i][1] - 'a')];
            fout << value1 << '\n';
            i++;
        }

        else if ((command[i][0] == 'C') && (command[i].length() == 1))
        {
            value1 = pop(pbeg, pend);
            fout << char(value1 % 256);
            i++;
        }

        else if (command[i][0] == 'C')
        {
            value1 = regis[(int)(command[i][1] - 'a')];
            fout << char(value1 % 256);
            i++;
        }

        else if (command[i][0] == ':')
        {
            i++;
        }

        else if (command[i][0] == 'J')
        {
            i = labelFind(command, label, i, n_label, 1);
        }

        else if (command[i][0] == 'Z')
        {
            if (regis[(int)(command[i][1] - 'a')] == 0)
            {
                i = labelFind(command, label, i, n_label, 2);
            }
            i++;
        }

        else if (command[i][0] == 'E')
        {
            if (regis[(int)(command[i][1] - 'a')] == regis[(int)(command[i][2] - 'a')])
            {
                i = labelFind(command, label, i, n_label, 3);
            }
            i++;
        }

        else if (command[i][0] == 'G')
        {
            if (regis[(int)(command[i][1] - 'a')] > regis[(int)(command[i][2] - 'a')])
            {
                i = labelFind(command, label, i, n_label, 3);
            }
            i++;
        }

        else if (command[i][0] == 'Q')
        {
            fcin.close();
            fout.close();
            return 0;
        }
    }

    fcin.close();
    fout.close();
    return 0;
}