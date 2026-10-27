class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; 

       
        for (int i = 0; i < 2 * n; ++i) {
            int currentIndex = i % n;
            
            while (!st.empty() && nums[st.top()] < nums[currentIndex]) {
                result[st.top()] = nums[currentIndex];
                st.pop();
            }
            
           
            if (i < n) {
                st.push(currentIndex);
            }
        }
        
        return result;
    }
};
// extended array question
