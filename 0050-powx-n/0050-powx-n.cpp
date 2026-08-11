class Solution {
public:
    double myPow(double x, int n) {
        
        long long power = n; 
        
        if (power < 0) {
            power = -power;
            x = 1.0 / x;
        }
        
        double ans = 1.0;
        
        while (power > 0) {
            if (power % 2 == 1) {
                ans = ans * x;
                power = power - 1;
            } 
            else {
                x = x * x;
                power = power / 2;
            }
        }
        
        return ans;
    }
};