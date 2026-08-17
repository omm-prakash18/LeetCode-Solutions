class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ans;

        while (left < right)
        {
            int currentSum = numbers[left] + numbers[right];

            if (target == currentSum)
            {
                ans.push_back(left + 1);  // LeetCode "Two Sum II" usually expects 1-based indices
                ans.push_back(right + 1); // Use numbers[left] and numbers[right] if you need values instead
                return ans;               // Return immediately to prevent an infinite loop
            }
            else if (target > currentSum) // Fixed: Added missing closing parenthesis here
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
        return ans;
    }
};
