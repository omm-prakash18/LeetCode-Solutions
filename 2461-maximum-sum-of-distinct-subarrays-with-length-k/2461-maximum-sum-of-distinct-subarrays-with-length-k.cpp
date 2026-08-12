

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> windowSet;
        long long maxSum = 0;
        long long currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) 
        {
            
            while (windowSet.count(nums[right])) 
            {
                windowSet.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }

            windowSet.insert(nums[right]);
            currentSum += nums[right];

            if (right - left + 1 > k) {
                windowSet.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
            if (right - left + 1 == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};