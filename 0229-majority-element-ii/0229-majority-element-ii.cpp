class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> ls;
        map<int,int> mppp; 
        int n = nums.size();
        int mini = (int)(n/3) + 1;
        
        for(int i = 0; i < n; i++)
        {
            int m = nums[i];
            mppp[m]++; 
            
            if (mppp[m] == mini) 
            {
                ls.push_back(nums[i]); 
            }
            if (ls.size() == 2) break;
        }
        
        sort(ls.begin(), ls.end());
        return ls;
    }
};