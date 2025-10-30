//reverse string of numbers signed nd unsigned

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;
            
            result = result * 10 + digit;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << sol.reverse(123) << endl;
    cout << sol.reverse(-123) << endl;
    cout << sol.reverse(120) << endl;
    cout << sol.reverse(1534236469) << endl;
    
    return 0;
}