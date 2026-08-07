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
    void mirror(TreeNode* root){
        while(root!=nullptr){
        swap(root->left,root->right);
            root=root->right;
        }
    }
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        vector<int>preOrder;
        while(curr){
            if(curr->left==nullptr){
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr->right;
                    curr->right=nullptr;
                    swap(curr->left,curr->right);
                    curr=curr->right;
                }
            }
        }
    }
};