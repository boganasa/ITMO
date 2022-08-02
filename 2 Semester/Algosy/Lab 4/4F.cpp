#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fcin("garland.in");
    ofstream fout("garland.out");

    int n;
    double A, high, low, middle, prev, cur, next, last = -1;
    int key;

    fcin >> n;
    fcin >> A;
    high = A;
    low = 0;

    while (true)
    {
        middle = (high + low) / 2;

        if (middle == low || middle == high)
        {
            break;
        }

        prev = A;
        cur = middle;
        key = 0;

        if (cur > 0)
        {
            key = 1;
        }

        for (int i = 2; i < n; i++)
        {
            next = 2 * cur - prev + 2;
            if (next <= 0)
            {
                key = 0;
            }
            prev = cur;
            cur = next;
        }
        
        if (key == 1)
        {
            high = middle;
            last = cur;
        }
        else
        {
            low = middle;
        }
    }

    fout << fixed << setprecision(2) << last;

    fcin.close();
    fout.close();
    return 0;
}