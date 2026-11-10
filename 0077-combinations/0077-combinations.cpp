class Solution {
public:
   
    void backtrack(int start, int n, int k, vector<int>& temp, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }
        if (start > n) {
            return;
        }
        
        
        temp.push_back(start);
        backtrack(start + 1, n, k - 1, temp, result); 
        temp.pop_back();
        backtrack(start + 1, n, k, temp, result);     // k stays the same
    } 

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> result;
        
       
        backtrack(1, n, k, temp, result);
        
        return result;
    }
};