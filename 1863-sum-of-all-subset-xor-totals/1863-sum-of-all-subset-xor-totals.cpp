class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int bitwise_or =0;
        for(auto &num :nums)
        {
            bitwise_or |=num;
        }
        return (bitwise_or * (pow(2, (nums.size()-1))));
    }
};