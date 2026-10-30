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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    bool forword =true;
    while (!q.empty()) {
        int level_size = q.size();
        vector<int> current_level;

        for (int i = 0; i < level_size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            if(forword)
            {
                current_level.push_back(curr->val);
            }
            else{
                current_level.insert(current_level.begin(), curr->val);
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result.push_back(current_level);
        forword =!forword;
    }
    return result;
    }
};


