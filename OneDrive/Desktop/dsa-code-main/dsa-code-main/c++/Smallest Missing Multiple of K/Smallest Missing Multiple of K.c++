class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set <int> st ;
        for (int i = 0 ;i < nums.size() ;i++) {
            st.insert(nums[i]) ;
        }
        int j = 0 ;
        int i = 1 ;
        while(true) {
            if (i % k == 0 && st.find(i) == st.end()) {
                return i ;
            }
            i++ ;
        }
        return i ;
    }
};