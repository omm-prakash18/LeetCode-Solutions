class Solution {
public:
    void backtrack(vector<string> &result, string temp, int open_count, int close_count, int n)
    {
        if (temp.size() == 2 * n)
        {
            result.push_back(temp);
            return;
        }
        if (open_count < n)
        {
            backtrack(result, temp + '(', open_count + 1, close_count, n);
        }
        if (close_count < open_count)
        {
            backtrack(result, temp + ')', open_count, close_count + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};