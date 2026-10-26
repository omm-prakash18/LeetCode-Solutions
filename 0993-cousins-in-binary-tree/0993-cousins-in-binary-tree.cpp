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
    int findh(TreeNode* curr,int &parent,int value,int height )
    {
        if(!curr)
        {
            return 0;
        
        }
        if (curr->val == value)
        {
            return height;
        }
        parent = curr->val;
        int left =findh(curr->left, parent,value,height+1);
        if(left)
        {
            return left;
        }
        parent = curr->val;
        int right =findh(curr->right, parent,value,height+1);
        if(right)
        {
            return right;
        }
        return 0;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)
        {
            return false;
        }
        int x_parent =-1;
        int x_h =findh(root,x_parent,x,0);
        int y_parent =-1;
        int y_h =findh(root,y_parent,y ,0);

        if(x_parent != y_parent && x_h == y_h)
        {
            return true;
        }
        return false;
    }
};