#include <bits/stdc++.h>
using namespace std;
    int solve(unordered_map<char,int> &mp){
        int mini = INT_MAX, maxi = 0;
        for (auto &p : mp) {
            mini = min(mini, p.second);
            maxi = max(maxi, p.second);
        }
        return mini == maxi;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char,int> mp;  
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                if (solve(mp)) {
                    int l = j - i + 1;
                    ans = max(ans, l);
                }
            }
        }
        return ans;
    }
int main(){
    string s;
    cout << "Enter the string : ";
    cin >> s;
    cout << "Length of Longest Balanced Substring is : " << longestBalanced(s) << endl;
    return 0;
}