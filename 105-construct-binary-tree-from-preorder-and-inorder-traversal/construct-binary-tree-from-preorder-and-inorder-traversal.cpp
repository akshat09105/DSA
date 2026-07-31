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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
        
    }
    TreeNode* tree(vector<int>&preOrder,int preOrderStart,int preOrderEnd,vector<int>&InOrder,int InOrderStart,int InOrderEnd,unordered_map<int,int>&mpp){
        if(preOrderStart>preOrderEnd||InOrderStart>InOrderEnd)return nullptr;
        TreeNode* root=new TreeNode(preOrder[preOrderStart]);
        int indexIO=mpp[preOrder[preOrderStart]];
        int left=indexIO-InOrderStart;
        root->left=tree(preOrder,preOrderStart+1,preOrderStart+left,InOrder,InOrderStart,indexIO-1,mpp);
        root->right=tree(preOrder,preOrderStart+left+1,preOrderEnd,InOrder,indexIO+1,InOrderEnd,mpp);

        return root;


        

        
    }
};