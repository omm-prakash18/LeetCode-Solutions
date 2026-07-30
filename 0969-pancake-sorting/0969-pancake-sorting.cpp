class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        
        for (int target = n; target > 0; --target) 
        {
            int index = -1;
            for (int i = 0; i < target; ++i) 
            {
                if (arr[i] == target) 
                {
                    index = i;
                    break;
                }
            }
            if (index == target - 1) {
                continue;
            }
            if (index != 0) 
            {
                reverse(arr.begin(), arr.begin() + index + 1);
                result.push_back(index + 1); 
            }
            reverse(arr.begin(), arr.begin() + target);
            result.push_back(target);
        }
        
        return result;
    }
};