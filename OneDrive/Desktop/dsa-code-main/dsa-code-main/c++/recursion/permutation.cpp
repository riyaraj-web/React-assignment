// Permutation of array {1,2,3};

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void func(vector<int> flag, int x, vector<int> ans)
{
    if (x == 3) {
        result.push_back(ans);
        return;
    }

    if (flag[0] != 1) {
        vector<int> tempFlag = flag;        // Copy to preserve original state
        vector<int> tempAns = ans;
        tempFlag[0] = 1;
        tempAns.push_back(1);
        func(tempFlag, x + 1, tempAns);     // Pass x+1 directly
    }

    if (flag[1] != 1) {
        vector<int> tempFlag = flag;
        vector<int> tempAns = ans;
        tempFlag[1] = 1;
        tempAns.push_back(2);
        func(tempFlag, x + 1, tempAns);
    }

    if (flag[2] != 1) {
        vector<int> tempFlag = flag;
        vector<int> tempAns = ans;
        tempFlag[2] = 1;
        tempAns.push_back(3);
        func(tempFlag, x + 1, tempAns);
    }
}

int main()
{
    vector<int> flag = {0, 0, 0};
    vector<int> ans;
    func(flag, 0, ans);

    for (auto x : result) {
        for (int i = 0; i < 3; i++) {
            cout << x[i];
        }
        cout << endl;
    }

    return 0;
}
