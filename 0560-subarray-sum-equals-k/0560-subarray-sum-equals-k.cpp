

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefSumCounts;
        prefSumCounts[0] = 1; 
        int currentSum = 0;
        int totalSubarrays = 0;
        
        for (int num : nums) {
            currentSum += num;
            
            
            if (prefSumCounts.count(currentSum - k)) {
                totalSubarrays += prefSumCounts[currentSum - k];
            }
            
            prefSumCounts[currentSum]++;
        }
        
        return totalSubarrays;
    }
};
