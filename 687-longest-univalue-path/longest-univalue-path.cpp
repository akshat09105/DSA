/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int solve(TreeNode* root, int &maxi) {

        if(root == nullptr)
            return 0;

        int lh = solve(root->left, maxi);
        int rh = solve(root->right, maxi);

        int leftPath = 0;
        int rightPath = 0;

        if(root->left && root->left->val == root->val)
            leftPath = lh + 1;

        if(root->right && root->right->val == root->val)
            rightPath = rh + 1;

        // Same as diameter
        maxi = max(maxi, leftPath + rightPath);

        // Return longest chain to parent
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {

        int maxi = 0;
        solve(root, maxi);

        return maxi;
    }
};