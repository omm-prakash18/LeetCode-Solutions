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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateDepth(root, maxDiameter);
        return maxDiameter;
    }

private:
    
    int calculateDepth(TreeNode* root, int& maxDiameter) {
        if(!root)
        {
            return 0;
        }

        int left =calculateDepth(root->left,maxDiameter);
        int right =calculateDepth(root->right,maxDiameter);

        maxDiameter =max(maxDiameter,left+right);

        return max(left,right)+1;

   }
};

//important
