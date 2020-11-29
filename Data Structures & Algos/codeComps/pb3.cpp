// https://codeforces.com/problemset/problem/1446/B

#include <iostream>
#include <string.h>
using namespace std;
class LCS
{
public:
    /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
    int FIND_LCS(char *X, char *Y, int m, int n)
    {
        int L[m + 1][n + 1];
        int i, j;

        for (i = 0; i <= m; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    L[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;

                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }

        return L[m][n];
    }
    /* Utility function to get max of 2 integers */
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    char *subString(char str[], int n)
    {
        // Pick starting point
        for (int len = 1; len <= n; len++)
        {
            // Pick ending point
            for (int i = 0; i <= n - len; i++)
            {
                //  Print characters from current
                // starting point to current ending
                // point.
                int j = i + len - 1;
                for (int k = i; k <= j; k++)
                    return str;
            }
        }
    }
};
class solve : public LCS
{
public:
    void SOLVE()
    {
        int m, n;
        cout << "N :: ";
        cin >> n;
        cout << "M :: ";
        cin >> m;

        if (n < 1 && m > 500)
            return;

        char s1[n + 1], s2[m + 1];

        cout << "S1 :: ";
        cin >> s1;
        cout << "S2 :: ";
        cin >> s2;

        char *R[10], *S[10];
        int res[m], end;

        for (int i = 0; i < 11; i++)
        {
            R[i] = subString(s1, strlen(s1));
            S[i] = subString(s2, strlen(s2));
            res[i] = FIND_LCS(R[i], S[i], strlen(R[i]), strlen(S[i]));
            end = (4 * res[i]) - res[i] - strlen(S[i]);
            cout << "FINAL :: " << endl;
        }
    }
};
int main()
{
    cout << "START : " << endl;

    solve sudo;
    sudo.SOLVE();
    return 0;
}