#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Tree
{
    long long key;
    int left;
    int right;
};

bool tree_check(Tree **binTree, long long tree_min, long long tree_max, int i)
{
    if (i < 0)
    {
        return true;
    }
    if ((binTree[i]->key <= tree_min) || (binTree[i]->key >= tree_max))
    {
        return false;
    }
    return (tree_check(binTree, tree_min, binTree[i]->key, binTree[i]->left - 1) && tree_check(binTree, binTree[i]->key, tree_max, binTree[i]->right - 1));
}

int main()
{
    ifstream fcin("check.in");
    ofstream fout("check.out");

    int n, key_check;
    long long key_min = -1000000001, key_max = 1000000001;
    fcin >> n;
    Tree **binTree = new Tree *[n];

    if (n == 0)
    {
        fout << "YES";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        binTree[i] = new Tree[3];
        fcin >> binTree[i]->key >> binTree[i]->left >> binTree[i]->right;
    }

    bool rezult = tree_check(binTree, key_min, key_max, 0);
    if (rezult)
    {
        fout << "YES";
    }
    else
    {
        fout << " NO";
    }

    fcin.close();
    fout.close();
    return 0;
}