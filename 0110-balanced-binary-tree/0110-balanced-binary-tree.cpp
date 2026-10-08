class Solution {
public:

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int left = height(root->left);
        int right =height(root->right);

        if(abs(left-right ) >1)
        {
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
//important

       