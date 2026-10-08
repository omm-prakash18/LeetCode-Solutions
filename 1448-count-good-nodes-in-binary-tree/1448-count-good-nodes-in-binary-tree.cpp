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
    int goodNodes(TreeNode* root) {
        return helper(root,0,INT_MIN);
    }

private:
    int helper (TreeNode* root,int ans,int currentMax)
    {
        if(!root)
        {
            return 0;
        }
        int rootAnswer = 0;
        if(root->val >= currentMax)
        {
            rootAnswer =1;
            currentMax =root->val;
        }
        int left = helper(root->left,ans,currentMax);
        int right = helper(root->right,ans,currentMax);

        return (left+right+rootAnswer);
    }
};
// another banger question