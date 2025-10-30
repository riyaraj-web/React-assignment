#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// 📘 BITWISE OPERATORS IN C++ (With Examples)
// ---------------------------------------------------------
// Bitwise operators work directly on the binary representation
// of integers. They are used for efficient computations,
// system-level programming, and competitive programming.
// ---------------------------------------------------------

int main() {
    int a = 5;   // binary: 0101
    int b = 3;   // binary: 0011

    cout << "--------------------------------------\n";
    cout << "Bitwise Operators in C++ Explained    \n";
    cout << "--------------------------------------\n\n";

    //  BITWISE AND (&)
    // Performs AND operation on each bit.
    // 0101 & 0011 = 0001  (which is 1)
    cout << "1. AND (&): " << (a & b) << endl;

    //  BITWISE OR (|)
    // Performs OR operation on each bit.
    // 0101 | 0011 = 0111  (which is 7)
    cout << "2. OR (|): " << (a | b) << endl;

    //  BITWISE XOR (^)
    // XOR gives 1 only when bits are different.
    // 0101 ^ 0011 = 0110  (which is 6)
    cout << "3. XOR (^): " << (a ^ b) << endl;

    //  BITWISE NOT (~)
    // Inverts all bits. It also changes the sign due to 2's complement.
    // For example, ~5 = -(5+1) = -6
    cout << "4. NOT (~): " << (~a) << endl;

    //  LEFT SHIFT (<<)
    // Moves all bits to the left and fills 0s on the right.
    // 5 << 1 = 10 (0101 -> 1010)
    cout << "5. LEFT SHIFT (<<): " << (a << 1) << endl;

    //  RIGHT SHIFT (>>)
    // Moves all bits to the right and discards bits on the right.
    // 5 >> 1 = 2 (0101 -> 0010)
    cout << "6. RIGHT SHIFT (>>): " << (a >> 1) << endl;

    cout << "\n--------------------------------------\n";
    cout << "Additional Examples and Notes 💡\n";
    cout << "--------------------------------------\n";

    // Check if k-th bit is set
    int n = 10; // binary: 1010
    int k = 2;
    cout << "Is " << k << "th bit of " << n << " set? "
         << ((n & (1 << k)) ? "Yes" : "No") << endl;

    // Set the k-th bit
    cout << "Setting " << k << "th bit of " << n << ": " << (n | (1 << k)) << endl;

    // Clear the k-th bit
    cout << "Clearing " << k << "th bit of " << n << ": " << (n & ~(1 << k)) << endl;

    // Toggle the k-th bit
    cout << "Toggling " << k << "th bit of " << n << ": " << (n ^ (1 << k)) << endl;

    cout << "\n End of Bitwise Operator Demonstration\n";
    return 0;
}
