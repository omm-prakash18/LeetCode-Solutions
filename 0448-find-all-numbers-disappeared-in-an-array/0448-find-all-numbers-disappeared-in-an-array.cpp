class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missing; 
        sort(nums.begin(), nums.end());
        
        int expected = 1; 
        
        for (int i = 0; i < nums.size(); i++) 
        {
            if (i > 0 && nums[i] == nums[i-1]) 
            {
                continue; 
            }
            while (expected < nums[i]) 
            {
                missing.push_back(expected);
                expected++;
            }
            
            expected++; 
        }
        
        
        while (expected <= nums.size()) {
            missing.push_back(expected);
            expected++;
        }
        
        return missing;
    }
};