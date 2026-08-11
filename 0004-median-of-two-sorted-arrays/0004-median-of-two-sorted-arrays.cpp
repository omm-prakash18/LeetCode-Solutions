class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> merged;
        
        int i = 0; 
        int j = 0; 
        
        
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        
        while (i < n1) {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < n2) {
            merged.push_back(nums2[j]);
            j++;
        }
        
        
        int total = merged.size();
        
        if (total % 2 != 0) {
            
            return (double)merged[total / 2];
        } else {
           
            return (double)(merged[(total / 2) - 1] + merged[total / 2]) / 2.0;
        }
    }
};