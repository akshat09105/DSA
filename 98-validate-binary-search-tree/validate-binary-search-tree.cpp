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
    bool fn(TreeNode* root,long long Low,long long High) {
        if(root==nullptr){
            return true;
        }
        if(!((long long)root->val>Low)||!((long long)root->val<High)){
            return false;
        }
        if(fn(root->left,Low,root->val)!=true)return false;
        if(fn(root->right,root->val,High)!=true)return false;
        return true;

    }

    bool isValidBST(TreeNode* root) {
        return fn(root,LLONG_MIN,LLONG_MAX);
    }
};