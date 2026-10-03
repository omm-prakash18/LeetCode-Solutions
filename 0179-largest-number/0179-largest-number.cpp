class Solution {
public:
    // Custom comparator function
    static bool compare(string a, string b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        
        for(int i = 0; i < nums.size(); i++) {
            strNums.push_back(to_string(nums[i]));
        }
       
        sort(strNums.begin(), strNums.end(), compare);
        
        
        if(strNums[0] == "0") {
            return "0";
        }
       
        string result = "";
        for(int i = 0; i < strNums.size(); i++) {
            result += strNums[i];
        }
        
        return result;
    }
};