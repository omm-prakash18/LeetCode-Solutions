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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
       
        getRightView(root, 0, ans);
        return ans;
    }

private:
    void getRightView(TreeNode* node, int level, vector<int>& ans) {
        if (!node) {
            return;
        }
        
        if (ans.size() == level) {
            ans.push_back(node->val);
        }
      
        getRightView(node->right, level + 1, ans);
        
        
        getRightView(node->left, level + 1, ans);
    }
};