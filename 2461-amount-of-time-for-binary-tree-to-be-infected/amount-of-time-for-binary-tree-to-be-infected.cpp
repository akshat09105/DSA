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
    void parent_mark(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mpp){
        queue<TreeNode*>q;
        q.push(root);
        mpp[root]=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    TreeNode* find_start(TreeNode* root,int start){
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==start){
            return root;
        }
        TreeNode* left=find_start(root->left,start);
        if(left!=nullptr){
            return left;
        }
        TreeNode* right=find_start(root->right,start);
        if(right!=nullptr){
            return right;
        }
        return nullptr;
    }
    int amountOfTime(TreeNode* root, int start) {
       unordered_map<TreeNode*,TreeNode*>mpp;
       parent_mark(root,mpp);
       TreeNode* node=find_start(root,start);
       queue<TreeNode*>q;
       q.push(node);int level=0;
       unordered_map<TreeNode*,bool>Traversed;
       Traversed[node]=true;
       while(!q.empty()){
           int size=q.size();
           level++;
           for(int i=0;i<size;i++){
               node=q.front();
               q.pop();
               if(node->left&&!Traversed[node->left]){
                q.push(node->left);
                Traversed[node->left]=true;
               }
               if(node->right&&!Traversed[node->right]){
                q.push(node->right);
                Traversed[node->right]=true;
               }
               if(mpp[node]&&!Traversed[mpp[node]]){
                q.push(mpp[node]);
                Traversed[mpp[node]]=true;
               }
            }
       }
       return level-1;



    }
};