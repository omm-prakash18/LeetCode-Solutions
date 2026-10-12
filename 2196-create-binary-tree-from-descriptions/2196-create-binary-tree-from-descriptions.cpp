class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> hasParent;
        
        for(auto description : descriptions) {
          
            int parentVal = description[0], childVal = description[1], isleft = description[2];
            TreeNode* parentNode = nullptr; 
            TreeNode* childNode = nullptr;
            
            if(mp.find(parentVal) == mp.end()) parentNode = new TreeNode(parentVal);
            else parentNode = mp[parentVal];
            
           
            if(mp.find(childVal) == mp.end()) childNode = new TreeNode(childVal);
            else childNode = mp[childVal];

            if(isleft) parentNode->left = childNode;
            else parentNode->right = childNode;

            hasParent[childVal] = true;
            mp[childVal] = childNode;
            mp[parentVal] = parentNode;
        }
        
        TreeNode* rootNode = nullptr;
        for(auto& [nodeVal, node] : mp) {
            if(!hasParent[nodeVal]) {
                 rootNode = node;
                 break; 
            }
        }
       
        return rootNode; 
    }
};