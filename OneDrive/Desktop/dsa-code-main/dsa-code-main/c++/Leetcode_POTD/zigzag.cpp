//zigzag problem

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(min(numRows, (int)s.length()));
        int currRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }
        
        string result;
        for (string row : rows) result += row;
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << sol.convert("PAYPALISHIRING", 3) << endl;
    cout << sol.convert("PAYPALISHIRING", 4) << endl;
    cout << sol.convert("A", 1) << endl;
    
    return 0;
}