// array arrangement
// codeforces
// https://codeforces.com/contest/1445/problem/A
// SOLVED

#include <iostream>
using namespace std;
void solveProblem()
{
    unsigned int t;
    cout << "T : ";
    cin >> t;

    try
    {
        if (1 <= t <= 100)
        {
            for (int test = 0; test < t; test++)
            {
                unsigned int n = 0, x = 0, checker = 0;
                cout << "N and X : ";
                cin >> n;
                cin >> x;

                int i, j;
                int a[n], b[n];

                for (i = 0; i < n; i++)
                {
                    cout << " A : ";
                    cin >> a[i];
                }

                for (i = 0; i < n; i++)
                {
                    cout << " B : ";
                    cin >> b[i];
                }

                for (i = 0; i < n; i++)
                {
                    j = 0;
                    while (j < n)
                    {
                        if ((a[i] + b[j]) <= x)
                        {
                            if (i != j)
                            {
                                swap(b[i], b[j]);
                            }
                            checker++;
                            break;
                        }
                        else
                        {
                            j++;
                        }
                    }
                }

                if (checker == n)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }

                cout << endl;
            }
        }
        else
        {
            throw "TEST CASE OUT OF RANGE ERROR";
        }
    }
    catch (string TestCaseError)
    {
        cout << "ENCOUNTERED : " << TestCaseError << endl;
    }
}
int main()
{
    solveProblem();
    return 0;
}