class Node {
public:
    int MIN_NUM, MAX_NUM, Sum;
    Node(int min_n, int max_n, int s) : MIN_NUM(min_n), MAX_NUM(max_n), Sum(s) {}
};

class Solution {
private:
    int maxSum = 0;

public:
    Node SumFinder(TreeNode* node) {
        if (node == nullptr) {
            return Node(INT_MAX, INT_MIN, 0);
        }

        auto left = SumFinder(node->left);
        auto right = SumFinder(node->right);

        if (left.MAX_NUM < node->val && node->val < right.MIN_NUM) {
            int currSum = left.Sum + node->val + right.Sum;
            maxSum = max(maxSum, currSum);

            int minVal = min(node->val, left.MIN_NUM);
            int maxVal = max(node->val, right.MAX_NUM);

            return Node(minVal, maxVal, currSum);
        }

        return Node(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        SumFinder(root);
        return maxSum;
    }
};