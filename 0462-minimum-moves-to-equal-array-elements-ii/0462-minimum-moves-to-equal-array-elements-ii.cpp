class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort to find the median
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int median = nums[n / 2];
        int moves = 0;
        
        
        for (int num : nums) {
            moves += abs(num - median);
        }
        
        return moves;
    }
};