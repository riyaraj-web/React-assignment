/************************************************ */
/*          Solution 1 Using two pointer          */
/************************************************ */

class Solution {
    public int trap(int[] height) {
        int l = 0, r = height.length - 1;
        int lmax = height[l], rmax = height[r];
        int water = 0;
        
        while(l < r){
            if(lmax <= rmax){
                ++l;
                if(height[l] >= lmax)
                    lmax = height[l];
                else
                    water += lmax - height[l];
                
            } else {
                --r;
                if(height[r] >= rmax)
                    rmax = height[r];
                    
                else
                    water += rmax - height[r];
            }
        }
        return water;
    }
}

/* =====================================================================================================================
                    TIME COMPLEXITY ANALYSIS FOR THE ABOVE CODE:

 The time complexity of the above code is O(n) where n = height.length.

 Explanation : The condition "while(l < r)" loop runs once for each element in the array. So, each element is processed atmost once
=======================================================================================================================

                    SPACE COMPLEXITY ANALYSIS FOR THE ABOVE CODE :

The space complexity of the above code is O(1) and I say that because the extra space is being used only by the variables (l, r, lmax, rmax, water) and no additional Data Structures and being used.
========================================================================================================================
*/


/************************************************ */
/*          Solution 2 Using arrays               */
/************************************************ */

// class Solution {
//     public int trap(int[] height) {
//         int[] leftMax = new int[height.length];
//         int[] rightMax = new int[height.length];
//         int water = 0;

//         leftMax[0] = height[0];
//         rightMax[height.length - 1] = height[height.length - 1];

//         for(int i = 1; i < height.length; i++)
//             leftMax[i] = Math.max(leftMax[i-1],height[i]);

//         for(int i = (height.length - 2); i >= 0; i--)
//             rightMax[i] = Math.max(rightMax[i+1],height[i]);
        
//         for(int i = 0; i < height.length; i++)
//             water += Math.min(rightMax[i],leftMax[i]) - height[i];
        
//         return water;
//     }
// }

/* =====================================================================================================================
                    TIME COMPLEXITY ANALYSIS FOR THE ABOVE CODE:

Explanation : As this code consists of traverising the array multiple times, let's go step by step:
First loop : It is calculating the values for left max array and the loop runs n-1 times (Time complexity : O(n)).
Second loop : It is calulating the values for the right max array and the lop runs n-1 times (Time complexity : O(n)).
Third loop : It is calculating the overall final value (final trapped water) and it runs n times (Time complexity : O(n)).

where is n = height.length.

Overall Time complexity : O(n) + O(n) + O(n) = O(n).
 
=======================================================================================================================

                    SPACE COMPLEXITY ANALYSIS FOR THE ABOVE CODE :
Explanation : The array leftmax and rightmax are of size n. So, O(n) + O(n) = O(2n). 
Also, there are few more variables being used like : water, i etc. 

Total Space Complexity : O(2n) => simplifies to O(n).


========================================================================================================================
*/


/************************************************ */
/*          Solution 2 Using stacks               */
/************************************************ */


// class Solution {
//     public int trap(int[] height) {
        
//         int water = 0, baseHeight = height[0];
//         Stack<Integer> st = new Stack<>();
//         Stack<Integer> st2 = new Stack<>();

//         st.push(height[0]);

//         for(int i = 1; i < height.length; i++) {
            
//             if(baseHeight <= height[i]) {
//                 while(!st.empty()){
//                     water += baseHeight - st.pop();
//                 }
//                 baseHeight = height[i];
//                 st.push(height[i]);
//             } else {
//                 st.push(height[i]);
//             }
//         }

//         baseHeight = st.pop();
//         while(!st.empty()) {
//             if(baseHeight <= st.peek()) {
//                 while(!st2.empty()){
//                     water += baseHeight - st2.pop();
//                 }
//                 baseHeight = st.pop();
//                 st2.push(baseHeight);
//             } else {
//                 st2.push(st.pop());
//             }
//         }

//         return water;
//     }
// }


/* =====================================================================================================================
                    TIME COMPLEXITY ANALYSIS FOR THE ABOVE CODE:

Explanation : As the code looks little bulky, let's analyze the time complexity of the above code step by step : 
First while loop :
-> It runs once for each element i in height array.
-> The inner  loop "while(!st.isEmpty())" pops elements from the stack. 

Second while loop : 
-> It processes the remaining elements in "st" and moves them into "st2".
-> Again, each element is pushed and popped at most once across both stacks. 


Thus, even though there are nested loops, each element is processed a constant number of times.

Time Complexity : O(n)
 
=======================================================================================================================

                    SPACE COMPLEXITY ANALYSIS FOR THE ABOVE CODE :
Explanation : 
                        Stack<Integer> st = new Stack<>();
                        Stack<Integer> st2 = new Stack<>();

The above 2 lines in the code, the stack uses upto n elements. 
The second stack uses upto n elements.
-> Here too, few constant variables are being used (like baseHeight, water etc).

Overall Space Complexity : O(n).


========================================================================================================================
*/
