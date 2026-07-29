/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_mark(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_node){
        queue<TreeNode*>q;
        q.push(root);
        parent_node[root]=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent_node[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent_node[node->right]=node;
                q.push(node->right);
            }

        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //first we need to make a ds which stores parent of each node so that we can traverse backward
        unordered_map<TreeNode*,TreeNode*>parent_node;
        parent_mark(root,parent_node);
        unordered_map<TreeNode*,bool>traversed;
        queue<TreeNode*>q;
        q.push(target);
        traversed[target]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level++==k)break;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !traversed[node->left]){
                    q.push(node->left);
                    traversed[node->left]=true;
                }
                if(node->right && !traversed[node->right]){
                    q.push(node->right);
                    traversed[node->right]=true;
                }
                if(parent_node[node] && !traversed[parent_node[node]]){
                    q.push(parent_node[node]);
                    traversed[parent_node[node]]=true;
                } 
            }

        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;

    }
};