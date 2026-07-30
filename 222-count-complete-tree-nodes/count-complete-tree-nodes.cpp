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
    int leftHeight(TreeNode* root){
        int hth=0;
        while(root){
            hth++;
            root=root->left;
        }
        return hth;
    }
    int rightHeight(TreeNode* root){
        int hth=0;
        while(root){
            hth++;
            root=root->right;
        }
        return hth;

    }
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh)return (1<<lh)-1;//as it given that it's a complete bt always when this condition satifies then it's a perfect bt
        return countNodes(root->left)+countNodes(root->right)+1;
    }
    
};