class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int size = 0;
        
        
        const long long MAX_PROD = 25200; 

        for (int left = 0; left < n; left++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;
            
            for (int right = left; right < n; right++) {
                long long x = nums[right];
                prod *= x;
                
               
                if (prod > MAX_PROD) break; 
                
                g = gcd(g, x);
                l = lcm(l, x);
                
                if (prod == l * g) {
                    size = max(size, right - left + 1);
                }
            }
        }
        return size;
    }
};