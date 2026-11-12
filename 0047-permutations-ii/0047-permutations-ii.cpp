class Solution {
public:
        void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, vector<bool>& visited) {
      
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
    

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            

            visited[i] = true;
            temp.push_back(nums[i]);
            backtrack(ans, nums, temp, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(), nums.end());
        backtrack(ans,nums,temp,visited);
        return ans;
    }
};