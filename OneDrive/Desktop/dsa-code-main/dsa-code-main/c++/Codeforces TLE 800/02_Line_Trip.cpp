#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fuelCal(vector<int> &arr, int x)
{

    arr.push_back(0);
    arr.push_back(x);
    
    sort(arr.begin(), arr.end());

    int s = arr.size();

    int maxGap = 0;
    for (size_t i = 1; i < arr.size(); i++)
    {

        if (i == s - 1)
        {
            maxGap = max(maxGap, 2 * (arr[i] - arr[i - 1]));
        }
        else
        {

            maxGap = max(maxGap, arr[i] - arr[i - 1]);
        }
    }

    cout << maxGap << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        fuelCal(arr, x);
    }
    return 0;
}
