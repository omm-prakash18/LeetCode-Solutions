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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(!root)
        {
            return new TreeNode(val);
        }
        if(val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
    
    vector<int> levelOrder(TreeNode* root) 
    {
        if (!root) {
            return {};
        }
        
        queue<TreeNode*> q;
        vector<int> ans;
        
        q.push(root);

        while(!q.empty())
        {
            int level = q.size();
            vector<int> store;

            for(int i = 0; i < level; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                store.push_back(node->val);
                
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            
            for(int j = 0; j < store.size(); j++)
            {
                ans.push_back(store[j]);
            }
        }
        
        return ans;
    }

    
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr; 
        }
        
       
        int mid = left + (right - left) / 2;
        
       
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
      
        return buildBST(nums, 0, nums.size() - 1);
    }
};