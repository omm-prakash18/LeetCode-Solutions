class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zero_count = 0;
        int max_length = 0;

        for (int right = 0; right < nums.size(); ++right) {
 
            if (nums[right] == 0) {
                zero_count++;
            }

            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--; 
                }
                left++;
            }

            int current_window_size = right - left + 1;
            max_length = max(max_length, current_window_size);
        }

        return max_length;
    }
};