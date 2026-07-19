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
    int sum(TreeNode* root,int &tiltsum){
        if(root==nullptr){
            return 0;
        }
        int leftsum=sum(root->left,tiltsum);
        int rightsum=sum(root->right,tiltsum);
        tiltsum+=abs(leftsum-rightsum);
        return leftsum+rightsum+root->val;
    }
    int findTilt(TreeNode* root) {
        int tiltsum=0;//if we will calcualte tiltsum directly we will end up getting o(n^2)tc
        //therefore trying it do in one go
        int summy=sum(root,tiltsum);
        return tiltsum;
    }
};