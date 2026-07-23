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
    bool isLeaf(TreeNode* root){
        if(root->left==nullptr&&root->right==nullptr){
            return true;
        }
        return false;
    }
    void paths(TreeNode* root,string path,vector<string>&ans){
        if(root==nullptr){
            return;
        }
        path+=(to_string(root->val));
        if(isLeaf(root)){
            ans.push_back(path);
            return;
        }
        path.push_back('-');
        path.push_back('>');
        paths(root->left,path,ans);
        paths(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path;
        paths(root,path,ans);
        return ans;

    }
};