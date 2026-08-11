class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        
        if (m == 0) {
            return false;
        }
        
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        
        int start = 0; 
        int end = m * n - 1;
        
        
        while(start <= end) 
        {
    
            int mid = start + (end - start) / 2; 
            int row = (mid / n);
            int col = (mid % n);
            int element = matrix[row][col];
            
            if (element == target) {
                return true;
            }
            else if(target < element) {
                end = mid - 1;
            }
            else {
                start = mid + 1; 
            }
        }
        
        return false; 
    }
};