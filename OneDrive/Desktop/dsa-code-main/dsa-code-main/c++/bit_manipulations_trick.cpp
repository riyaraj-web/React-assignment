#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------
// BIT MANIPULATION TRICKS EVERY PROGRAMMER SHOULD KNOW
// -------------------------------------------------------

int main() {
    int n = 5, a = 5, b = 9;

    // Check if number is even or odd
    cout << "1. " << n << " is " << ((n & 1) ? "Odd" : "Even") << endl;

    // Swap two numbers without using a temporary variable
    cout << "2. Before Swap: a=" << a << " b=" << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << " After Swap: a=" << a << " b=" << b << endl;

    // Check if a number is a power of 2
    n = 16;
    cout << "3. " << n << ((n & (n - 1)) == 0 ? " is" : " is not" ) << " a power of 2" << endl;

    // Count number of set bits (1s) in a number
    n = 29; // binary: 11101 → 4 bits set
    int count = __builtin_popcount(n); // built-in GCC function
    cout << "4. Number of set bits in " << n << " = " << count << endl;

    // Turn off the rightmost set bit
    n = 12; // binary: 1100
    int result = n & (n - 1);
    cout << "5. Turning off rightmost set bit in " << n << " gives " << result << endl;

    // Get the rightmost set bit (only)
    n = 10; // binary: 1010 → rightmost set bit is 2
    result = n & (-n);
    cout << "6. Rightmost set bit in " << n << " is " << result << endl;

    return 0;
}
