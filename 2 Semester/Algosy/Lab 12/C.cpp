#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void LCS(string s1, string s2, vector<vector<short> >& matrix, vector<vector<bool> >& flag)
{
    short m = s1.length();
    short n = s2.length();
    matrix.resize(2);
    flag.resize(m + 1);

    short i, j;
    for (i = 0; i < flag.size(); i++)
    {
        matrix[i % 2].resize(n + 1);
        flag[i].resize(n + 1);

    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                matrix[i % 2][j] = matrix[(i - 1) % 2][j - 1] + 1;
            }
            else if (matrix[(i - 1) % 2][j] >= matrix[i % 2][j - 1])
            {
                matrix[i % 2][j] = matrix[(i - 1) % 2][j];
                flag[i][j] = true;
            }
            else
            {
                matrix[i % 2][j] = matrix[i % 2][j - 1];
                flag[i][j] = false;
            }
        }
    }
}

void printLCS(vector<vector<bool> >& flag, string& s1, string& s2, short i, short j)
{
    stack<char> ans;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push(s1[i - 1]);
            i--;
            j--;
        }
        else if (flag[i][j] == true)
            i--;
        else
            j--;
    }

    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
}

int main()
{
    string s1;
    string s2;

    cin >> s1 >> s2;

    vector< vector<short> > matrix;
    vector< vector<bool> > flag;

    LCS(s1, s2, matrix, flag);
    matrix.shrink_to_fit();
    printLCS(flag, s1, s2, s1.size(), s2.size());
    flag.shrink_to_fit();

    cout << endl;

    return 0;
}