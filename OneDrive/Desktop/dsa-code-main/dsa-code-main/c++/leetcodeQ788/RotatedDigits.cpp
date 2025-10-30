/*
Problem: Rotated Digits (LeetCode 788)

An integer x is "good" if after rotating each digit individually by 180 degrees,
we get a valid number that is different from x.

Valid rotations:
0 -> 0
1 -> 1
2 <-> 5
5 <-> 2
6 <-> 9
8 -> 8
9 <-> 6

Digits 3, 4, 7 are invalid.

Given n, return the count of good integers in range [1, n].

Example:
Input: n = 10
Output: 4
Explanation: The good numbers are 2, 5, 6, 9
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int rotatedDigits(int n) {
    // Map digit to its rotated value. -1 or missing means invalid
    unordered_map<int,int> rotate = {{0,0},{1,1},{2,5},{5,2},{6,9},{8,8},{9,6}};
    int good_count = 0;

    for(int num = 1; num <= n; num++){
        int temp = num;
        bool valid = true;   // Flag to check if all digits are rotatable
        bool changed = false; // Flag to check if at least one digit changes

        while(temp > 0){
            int digit = temp % 10;
            if(rotate.find(digit) == rotate.end()){
                valid = false;  // Invalid digit found
                break;
            }
            if(rotate[digit] != digit) changed = true; // Digit changes after rotation
            temp /= 10;
        }

        if(valid && changed) good_count++;
    }

    return good_count;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of good integers from 1 to " << n << " is: " 
         << rotatedDigits(n) << endl;

    return 0;
}
