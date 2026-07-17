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
    vector<int>inorderTransversalAnswer(TreeNode* root,vector<int>ans){
        if(root==nullptr){
            return ans;
        }
        ans=inorderTransversalAnswer(root->left,ans);
        ans.push_back(root->val);
        ans=inorderTransversalAnswer(root->right,ans);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        ans=inorderTransversalAnswer(root,ans);
        return ans;
    }
};