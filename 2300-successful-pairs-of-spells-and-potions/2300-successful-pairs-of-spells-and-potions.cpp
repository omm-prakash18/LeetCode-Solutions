class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        
        for (long long spell : spells)
        {
           
            int left = 0;
            int right = m - 1;
            int firstValidIndex = m;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                if ((long long)spell * potions[mid] >= success) {
                    firstValidIndex = mid;
                    right = mid - 1; 
                } else {
                    left = mid + 1; 
                }
            }
            ans.push_back(m - firstValidIndex);
        }
        return ans;
    }
};