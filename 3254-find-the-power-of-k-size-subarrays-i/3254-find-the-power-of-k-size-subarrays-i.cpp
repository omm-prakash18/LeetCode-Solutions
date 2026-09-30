class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int current_length = 1;
        
        if (k == 1) {
            return nums;
        }
        
        for (int i = 1; i < n; i++) {
           
            if (nums[i] == nums[i - 1] + 1) {
                current_length++;
            } else {
                current_length = 1; 
            }
            
           
            if (i >= k - 1) {
                if (current_length >= k) {
                    ans.push_back(nums[i]); 
                } else {
                    ans.push_back(-1); 
                }
            }
        }
        
        return ans;
    }
};