class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> store;
        map<int, int> hashmap;
        vector<int> result;
        
        
        for(int i = 0; i < nums2.size(); i++) {
            while(!store.empty() && nums2[i] > store.top()) {
                hashmap[store.top()] = nums2[i];
                store.pop();
            }
            store.push(nums2[i]);
        }
        
        while(!store.empty()) {
            hashmap[store.top()] = -1;
            store.pop();
        }
        
       
        for(int i = 0; i < nums1.size(); i++) {
            result.push_back(hashmap[nums1[i]]);
        }
        
        return result;
    }
};