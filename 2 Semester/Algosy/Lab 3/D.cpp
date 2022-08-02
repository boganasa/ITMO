#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct CommandKey
{
    int CommandNumber;
    long long CommandMeaning;
    int CommandIndex;
};


void SiftUp (CommandKey *arr, int i)
{
    while (arr[i].CommandMeaning < arr[(i - 1) / 2].CommandMeaning)
    {
        CommandKey var = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = var;
        i = (i - 1) / 2;
    }
}

void SiftDown (CommandKey *arr, int i, int n)
{
    int left, right, j;
    while (2 * i + 1 < n)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if ((right < n) && (arr[right].CommandMeaning < arr[left].CommandMeaning))
        {
            j = right;
        }

        if (arr[i].CommandMeaning <= arr[j].CommandMeaning)
        {
            break;
        }
        CommandKey var = arr[i];
        arr[i] = arr[j];
        arr[j] = var;
        i = j;
    }
}

int main()
{
    ifstream fcin("priorityqueue.in");
    ofstream fout("priorityqueue.out");
    string Command;
    int n = 0, queue = -1;
    long long x, y;
    CommandKey *arr = new CommandKey [1000001];
    while (fcin >> Command)
    {
        n++;

        if (Command == "push")
        {
            fcin >> x;
            queue++;
            arr[queue].CommandNumber = n;
            arr[queue].CommandMeaning = x;
            arr[queue].CommandIndex = queue;
            SiftUp (arr, queue);
        }

        else if (Command == "extract-min")
        {
            if (queue == -1)
            {
                fout << "*" << endl;
            }
            else
            {
                fout << arr[0].CommandMeaning << endl;
                arr[0] = arr[queue];
                queue--;
                SiftDown (arr, 0, queue + 1);
            }
        }

        else if (Command == "decrease-key")
        {
            fcin >> x >> y;
            for (int i = 0; i <= queue; i ++)
            {
                if (arr[i].CommandNumber == x)
                {
                    arr[i].CommandMeaning = y;
                    SiftUp (arr, i);
                    break;
                }
            }
        }
    }

    fcin.close();
    fout.close();
    return 0;
}
