class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string serialized = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node != nullptr) {
                serialized += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                serialized += "#,";
            }
        }

        return serialized;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                node->left=nullptr;
            }
            else{
                TreeNode* leftNode= new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            

            getline(s, str, ',');
            if (str == "#") {
                node->right=nullptr;
            }
            else{
                TreeNode* rightNode= new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
            
        }

        return root;
    }
};