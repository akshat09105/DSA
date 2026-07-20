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
    void reverse(vector<int>&arr){
        int left=0;int right=arr.size()-1;
        while(left<=right){
            swap(arr[left],arr[right]);
            left++;right--;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>dq;
        dq.push(root);
        bool flag=true;
        while(!dq.empty()){
            int size=dq.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* Node=dq.front();
                dq.pop();
                if(Node->left!=nullptr)dq.push(Node->left);
                if(Node->right!=nullptr)dq.push(Node->right);
                level.push_back(Node->val);
            }
            if(flag==true){
                ans.push_back(level);
                flag=false;
            }
            else{
                reverse(level);
                ans.push_back(level);
                flag=true;
            }

        }
        return ans;
        
    }
};