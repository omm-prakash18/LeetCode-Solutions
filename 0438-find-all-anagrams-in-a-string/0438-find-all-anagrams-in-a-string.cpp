class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        
        if (s.length() < p.length()) return ans;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

       
        for (int i = 0; i < p.length(); i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }
        if (pCount == sCount) {
            ans.push_back(0);
        }

        
        for (int i = p.length(); i < s.length(); i++) {
           
            sCount[s[i] - 'a']++;
            
            sCount[s[i - p.length()] - 'a']--;

            
            if (pCount == sCount) {
                ans.push_back(i - p.length() + 1);
            }
        }

        return ans;
    }
};