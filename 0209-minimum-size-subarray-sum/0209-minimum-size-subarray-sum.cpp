class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int minlen = INT_MAX;
        int left = 0;
        int n = nums.size();
        int currsum = 0;
        
        for (int right = 0; right < n; right++)
        {
            currsum += nums[right];
            
            while(currsum >= target)
            {
    
                minlen = min(minlen, right - left + 1);
                
                currsum -= nums[left];
                left++;
            }
        }
    
        return minlen != INT_MAX ? minlen : 0;
    }
};