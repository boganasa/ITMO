#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void getT(string x, int*& t)
{
    int i = 0;
    t[0] = -1;
    int j = -1;
    while (i < x.length())
    {
        while ((j > -1) && (x[i] != x[j]))
            j = t[j];
        i++;
        j++;
        if ((i < x.length()) && (x[i] == x[j]))
            t[i] = t[j];
        else
            t[i] = j;
    }     
}
    
vector <int> aG(string x, string y)
{
    int l;
    int* t = new int[x.length() + 1];
    vector <int>  v;

    getT(x, t);
   
    for (l = 1; x[l - 1] == x[l]; l++) {};
    if (l == x.length())
        l = 0;
       
    int i = l;
    int j = 0;
    int k = 0;

    while (j <= (y.length() - x.length()))
    {
        while ((i < x.length()) && (x[i] == y[i + j]))
            ++i;                               
        if (i >= x.length())
        {
            while ((k < l) && (x[k] == y[j + k]))
                ++k;
            if (k >= l)
                v.push_back(j);
        }
        j += i - t[i];
        if (i == l)
            k = max(0, k - 1);
        else if (t[i] <= l)
        {
            k = max(0, t[i]);
            i = l;
        }
        else
        {
            k = l;
            i = t[i];
        }  
    }
    return v;
}
                

int main()
{
	ifstream fcin("search2.in");
	ofstream fout("search2.out");

    string x, y;
    fcin >> x >> y;
    if (x.length() > y.length())
    {
        fout << 0;
        fcin.close();
        fout.close();
        return 0;
    }
    vector <int> answer = aG(x, y);

    fout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        fout << answer[i] + 1 << " ";
    }

    fcin.close();
    fout.close();
    return 0;
}