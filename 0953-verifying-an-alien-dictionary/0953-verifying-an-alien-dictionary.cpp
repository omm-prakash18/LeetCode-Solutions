class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>orders;
        int idx = 0;
        for(auto &c :order) 
        {
            orders[c] = idx++;
        }
        for(int i = 0; i < words.size() - 1; i++)
        {
            string w1 = words[i];
            string w2 = words[i + 1];
            bool sorted = false;
            int j=0;
            while(j<w1.size() && j<w2.size())
            {
                if (w1[j] != w2[j]) 
                {
                    if (orders[w1[j]] > orders[w2[j]]) 
                    {
                        return false;
                    }
                    sorted = true;
                    break;
                }
                j++;
            }
            if (!sorted && w1.length() > w2.length()) 
            {
                return false;
            }
        }
        return true;
    }
};