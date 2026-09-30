class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int current_length = 1;
        for (int i = 1; i < n + k - 1; i++) {
            
            if (colors[i % n] != colors[(i - 1) % n]) {
                current_length++;
            } else {
                current_length = 1; 
            }
            
            if (current_length >= k) {
                ans++;
            }
        }
        return ans;
    }
};