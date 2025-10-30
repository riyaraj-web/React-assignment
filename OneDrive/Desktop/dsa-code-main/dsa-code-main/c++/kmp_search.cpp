#include <iostream>
#include <vector>
using namespace std;

vector<int> lpsArr(const string &p) {
    int n = p.size(), len = 0, i = 1;
    vector<int> lps(n,0);
    while(i < n) {
        if(p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

void kmp(const string &t, const string &p) {
    vector<int> lps = lpsArr(p);
    int i = 0, j = 0, n = t.size(), m = p.size();
    while(i < n) {
        if(t[i] == p[j]) {
            i++; j++;
        }
        if(j == m) {
            cout << "Found at " << i - j << "\n";
            j = lps[j-1];
        } else if(i < n && t[i] != p[j]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
}

int main() {
    string t = "ABABDABACDABABCABAB";
    string p = "ABABCABAB";
    kmp(t, p);
    return 0;
}
