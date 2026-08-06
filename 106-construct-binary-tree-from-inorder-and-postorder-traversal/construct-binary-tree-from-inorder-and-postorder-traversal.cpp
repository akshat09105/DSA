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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return build(inorder,0,n-1,postorder,0,n-1,mpp);
        
    }
    TreeNode* build(vector<int>&inorder,int inStart,int inEnd,vector<int>&postOrder,int postStart,int postEnd,unordered_map<int,int>&mpp){
        if(inStart>inEnd)return nullptr;
        TreeNode* root=new TreeNode(postOrder[postEnd]);
        int inroot=mpp[postOrder[postEnd]];
        int left=inroot-inStart;
        root->left=build(inorder,inStart,inroot-1,postOrder,postStart,postStart+left-1,mpp);
        root->right=build(inorder,inroot+1,inEnd,postOrder,postStart+left,postEnd-1,mpp);
        return root;


    }


};