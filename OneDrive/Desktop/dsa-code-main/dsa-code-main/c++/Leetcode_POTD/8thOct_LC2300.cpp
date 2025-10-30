// Problem: Sucessful Pairs Of Spells and Potions
// Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions
// Date: 8th Oct 2025
// Author: Ankit
//Difficulty : Medium 

/*
Problem:
You are given two arrays — spells[] and potions[], and an integer 'success'.
A pair (i, j) is successful if spells[i] * potions[j] >= success.
For each spell, we need to count how many potions make the pair successful.

Approach:
1. Pair each spell with its original index and sort them by spell strength.
2. Sort potions array as well.
3. Use two pointers:
   - Move through spells from smallest to largest.
   - For each spell, move pointer j in potions from end to start
     until product < success.
   - The number of successful potions = total potions - (j + 1)
4. Store result according to original index of spell.

Time Complexity: O(n log n + m log m)
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //AnkitPratap's Solution
        vector<pair<int,int>>spell;
        for(int i=0;i<spells.size();i++)
        {
            spell.push_back({spells[i],i});
        }
        sort(spell.begin(),spell.end());
        sort(potions.begin(),potions.end());
        vector<int>ans(spells.size(),0);
        int i=0;
        int j=potions.size()-1;
        while(i<spells.size())
        {
            int curr=spell[i].first;
            int index=spell[i].second;
            while(j>=0 && (long long)curr*potions[j]>=success)j--;
            int val=potions.size()-(j+1);
            ans[index]=val;
            i++;
        }
        return ans;

        //Time Complexity - O(nlogn + mlogm) 
    }
};
