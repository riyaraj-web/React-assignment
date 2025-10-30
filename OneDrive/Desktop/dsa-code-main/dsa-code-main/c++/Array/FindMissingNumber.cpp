#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = -1;
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] == a[i+1]) continue; // skip duplicates
        if(a[i] + 1 != a[i+1])
        {
            ans = a[i] + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}