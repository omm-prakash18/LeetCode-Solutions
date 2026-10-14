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
void inorder(TreeNode* node, vector<int>& result) {
        if (!node) {
            return;
        } 
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> result;
        inorder(root,result);
        int min =INT_MAX;
        

        int n =result.size();
        for(int i=0;i<n-1;i++)
        {
            if(min>(result[i+1]-result[i]))
            {
                min=(result[i+1]-result[i]);
            }
        }
        return min;

    }
};