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
    int kthNO(TreeNode* root,int &count,int k){
        if(root==nullptr){
            return -1;
        }
        int left=kthNO(root->left,count,k);
        if(left!=-1){
            return left;
        }
        count++;
        if(count==k)return root->val;
        int right=kthNO(root->right,count,k);
        if(right!=-1)return right;
        return -1;

    }
    int kthSmallest(TreeNode* root, int k) {
        //now root points to smallest node
        int count=0;
        return kthNO(root,count,k);
    }
};