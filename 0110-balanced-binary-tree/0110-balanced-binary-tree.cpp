class Solution {
public:

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
private:
   
    int height(TreeNode* node) {
        if (!node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
};