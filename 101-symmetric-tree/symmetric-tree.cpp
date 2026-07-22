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
    bool check(TreeNode* A,TreeNode* B){
        if(A==nullptr&&B==nullptr){
            return true;
        }
        if(A==nullptr||B==nullptr){
            return false;
        }
        if(A->val!=B->val){
            return false;
        }
        if(!check(A->left,B->right))return false;
        if(!check(A->right,B->left))return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};