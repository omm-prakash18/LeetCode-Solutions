class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long min_val = *min_element(nums.begin(), nums.end());
        
        return sum - (nums.size() * min_val);
    }
};