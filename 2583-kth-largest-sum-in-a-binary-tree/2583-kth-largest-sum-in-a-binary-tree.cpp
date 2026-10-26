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
    vector<long long> levelSum(TreeNode* root) {
        vector<long long> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            long long currentLevelSum = 0; 
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevelSum += node->val;
                
              
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
           
            result.push_back(currentLevelSum);
        }
        
        return result;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> store;
        store = levelSum(root);
        
        
        if (store.size() < k) {
            return -1;
        }
        
        sort(store.begin(), store.end(), greater<long long>());
        return store[k-1];
    }
};