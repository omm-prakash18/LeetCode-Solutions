class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < n; right++) {
           
            freq[nums[right]]++;
        
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
          
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};