/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long ans=INT_MIN;
        while(!q.empty()){/*we will do level order traversal on top and bottom view also we did level order traversal only but there we don't need to level it up*/ 
        //but here we will need to do it levelly as we need to find first and last node of each level
        int mini=q.front().second;
        long long size=q.size();
        long long first,last;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front().first;
            long long curr=q.front().second-mini;
            q.pop();
            if(i==0)first=curr;
            if(i==size-1)last=curr;
            if(node->left)q.push({node->left,curr*2+1});
            if(node->right)q.push({node->right,curr*2+2});
        }        
        ans=max(ans,last-first+1);
        }
        return ans;
    }
};