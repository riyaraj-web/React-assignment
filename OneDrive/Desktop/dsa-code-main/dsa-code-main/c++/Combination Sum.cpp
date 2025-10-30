class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, comb, ans);
        return ans;
    }
    
private:
    void backtrack(const vector<int>& candidates, int remaining, int start,
                   vector<int>& comb, vector<vector<int>>& ans) {
        if (remaining == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            int x = candidates[i];
            if (x > remaining) {
                break;  // since sorted, no need to try further
            }
            comb.push_back(x);
            // we allow reuse of the same candidate, so we pass i not i+1
            backtrack(candidates, remaining - x, i, comb, ans);
            comb.pop_back();
        }
    }
};
