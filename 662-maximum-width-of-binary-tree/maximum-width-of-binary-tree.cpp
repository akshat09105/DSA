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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});long long ans=0;
        while(!q.empty()){
        long long left,right;
        int size=q.size();
        long long minE=q.front().second;
        for(int i=0;i<size;i++){
            long long curr=q.front().second-minE;
            TreeNode* node=q.front().first;
            q.pop();
            if(i==0)left=curr;
            if(i==size-1)right=curr;
            if(node->left)q.push({node->left,curr*2+1});
            if(node->right)q.push({node->right,curr*2+2});
        }
        ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};