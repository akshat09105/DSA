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
    TreeNode* rightMost(TreeNode* root){
        while(root->right!=nullptr){
            root=root->right;
        }
        return root;
    }
    TreeNode* solve(TreeNode* root){
        TreeNode* dummy=root->left;
        if(!root->left){
            return root->right;
        }
        if(!root->right){
            return root->left;
        }
        TreeNode* right=root->right;
        TreeNode* leftRightMost=rightMost(root->left);
        leftRightMost->right=right;
        delete(root);
        return dummy;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy=root;
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            return solve(root);
        }
        while(root){
            if(root->val>key){
                if(root->left&&root->left->val==key){
                    root->left=solve(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right&&root->right->val==key){
                    root->right=solve(root->right);
                    break;
                }
                else{
                    root=root->right;
                }

            }
        }
        return dummy;
    }
};