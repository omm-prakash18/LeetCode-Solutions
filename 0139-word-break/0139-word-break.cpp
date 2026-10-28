#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo; 
        return wordBreakHelper(s, wordSet, memo);
    }

private:
    bool wordBreakHelper(string key, const unordered_set<string>& wordDict, unordered_map<string, bool>& memo) {
        if (key.length() == 0) {
            return true;
        }

        
        if (memo.count(key)) {
            return memo[key];
        }

        for (int i = 1; i <= key.length(); i++) {
            string firstPart = key.substr(0, i);
            string secPart = key.substr(i);

            if (wordDict.count(firstPart) && wordBreakHelper(secPart, wordDict, memo)) {
               
                memo[key] = true; 
                return true;
            }
        }

      
        memo[key] = false; 
        return false;
    }
};