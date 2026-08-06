class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // 1. Handle the edge case of an empty array
        if (nums.empty()) return 0;

        // 2. Use .size() instead of .length()
        int n = nums.size();
        int j = 1;

        // 3. Start i at 1 since the first element is always unique
        for(int i = 1; i < n; i++)
        {
            if (nums[i] != nums[j-1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};