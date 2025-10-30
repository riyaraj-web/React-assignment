#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void solve(string &cells, int n)
{

    int e = 0;
    bool f = true;

    for (int i = 0; i < n; i++)
    {

        if (cells[i] == '.')
            e++;

        if (i > 0 && i < n - 1)
        {
            if (cells[i - 1] == '.' && cells[i] == '.' && cells[i + 1] == '.')
            {
                cout << 2 << endl;
                f = false;
                break;
            }
        }
    }
    if (f == true)
    {
        cout << e << endl;
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string cells;
        cin >> cells;

        solve(cells, n);
    }

    return 0;
}