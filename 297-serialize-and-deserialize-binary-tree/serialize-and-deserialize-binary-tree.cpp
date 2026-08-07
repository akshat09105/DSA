class Codec {
public:

    string serialize(TreeNode* root) {
        if(root==nullptr) return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node==nullptr) {
                s += "#,";
            } else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                node->left = nullptr;
            } else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');
            if(str == "#") {
                node->right = nullptr;
            } else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};