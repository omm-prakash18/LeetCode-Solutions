class Solution {
public:
    std::string removeDuplicates(std::string s, int k) {
        
        std::vector<std::pair<char, int>> stack;
        
        for (char c : s) {
           
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++; 
            } else {
                stack.push_back({c, 1}); 
            }
            

            if (stack.back().second == k) {
                stack.pop_back();
            }
        }
        std::string result = "";
        for (auto& p : stack) {
            result.append(p.second, p.first); 
        }
        
        return result;
    }
};