#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
private:
    int helper(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        int left = max(0, helper(node->left, maxSum));
        int right = max(0, helper(node->right, maxSum));
        maxSum = max(maxSum, node->val + left + right);
        return node->val + max(left, right);
    }
};

int main() {
    // Example: [1,2,3]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl; // Output: 6

    // Clean up memory (important for big trees in interviews)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
