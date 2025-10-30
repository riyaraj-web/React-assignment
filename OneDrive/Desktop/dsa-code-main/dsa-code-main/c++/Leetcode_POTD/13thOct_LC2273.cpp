// Problem: Find Resultant Array After Removing Anagrams
// Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/
// Date: 13th Oct 2025
// Author: Aastik Das
//Difficulty : Easy 

/*
You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.
In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions. 
Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".

Example 1:
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
One of the ways we can obtain the resultant array is by using the following operations:
- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","baba","cd","cd"].
- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
  Now words = ["abba","cd","cd"].
- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","cd"].
We can no longer perform any operations, so ["abba","cd"] is the final answer.
Example 2:

Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations are performed.
 
Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& a) {
        vector<string>ans;
        
        int n=a.size();
        if(n==1) return a;
        unordered_set<string>st;
        string os=a[0];
        sort(os.begin(),os.end()); 
        for(int i=1;i<n;i++)
        {
            string s=a[i];
            sort(s.begin(),s.end()); 
            // cout<<s<<endl;
            if(os!=s){
                if(i==1) ans.push_back(a[0]);
                ans.push_back(a[i]);
                st.insert(s);
                os=s;
                continue;
            } 
            if(st.find(s)==st.end()){
                st.insert(s);
                ans.push_back(a[i-1]);
                // cout<<"hi";
            }
            os=s;
        }
        return ans;
    }
};


/*
Approach Used in Code:
Initialize:
ans → vector to store the final result.
st → unordered set to track strings already added (sorted form).
os → sorted form of the previous string (originally first string).

Handle edge case:
if(n==1) return a;
If there is only one string in the array, return it as-is.
Iterate through the array:

For each string a[i], create a sorted version s.
Sorting the string allows easy comparison for anagrams, since anagrams have identical sorted character sequences.
Check if current string is an anagram of previous:

if(os != s){
    if(i == 1) ans.push_back(a[0]);
    ans.push_back(a[i]);
    st.insert(s);
    os = s;
    continue;
}


If the sorted string s is different from os (previous sorted string), it is not an anagram.
Add the previous string (if it’s the second element) and the current string to the result.
Update os to the current sorted string.
Handle consecutive anagrams:

if(st.find(s) == st.end()){
    st.insert(s);
    ans.push_back(a[i-1]);
}

If the current string is an anagram of the previous one, only keep the first occurrence.
Add the previous string to the result and update the set.
Return the final list:
return ans;

After processing all strings, ans contains the modified list with consecutive anagrams removed.
*/