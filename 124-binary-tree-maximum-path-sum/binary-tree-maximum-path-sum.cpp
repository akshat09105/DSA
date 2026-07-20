/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root,int &maxi){
        if(root==nullptr){
            return 0;
        }
        int lh=pathSum(root->left,maxi);
        int rh=pathSum(root->right,maxi);
        int x=max(root->val,root->val+lh);
        x=max(x,root->val+rh);
        int y=x;
        x=max(x,root->val+lh+rh);
        maxi=max(x,maxi);
        return y;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int sum=pathSum(root,maxi);
        return maxi;
    }
};