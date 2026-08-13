class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n =s.size();
        int maxlen =0;
        unordered_set<char> Set;
        int left =0;
        for(int right =0; right <n; right++)
        {
            while (Set.count(s[right])) 
            {
                Set.erase(s[left]);
                left++;
            }
            Set.insert(s[right]);
            maxlen =max(maxlen, (right-left +1));
        }
        return maxlen;
    }
};