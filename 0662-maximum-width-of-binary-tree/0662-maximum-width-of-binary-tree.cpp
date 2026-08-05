class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int width = 0;
        queue<pair<TreeNode*, unsigned long long>> storage;
        storage.push({root, 0});
        
        while (!storage.empty()) {
            int sized = storage.size();
            unsigned long long mmin = storage.front().second;
            unsigned long long first = 0, last = 0;
            
            for (int i = 0; i < sized; i++) {
                unsigned long long curId = storage.front().second - mmin;
                TreeNode* Node = storage.front().first;
                storage.pop();
                
                if (i == 0) first = curId;
                if (i == sized - 1) last = curId;
                
                if (Node->left) storage.push({Node->left, 2 * curId + 1});
                if (Node->right) storage.push({Node->right, 2 * curId + 2});
            }
            
            width = max(width, static_cast<int>(last - first + 1));
        }
        
        return width;
    }
};