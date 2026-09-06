class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        int n = tokens.size();
        
        for(int i = 0; i < n; i++) {
            
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int n1 = ans.top();
                ans.pop();
                int n2 = ans.top();
                ans.pop(); 
                
                
                if(tokens[i] == "+") {
                    ans.push(n2 + n1);
                } 
                else if(tokens[i] == "-") {
                    ans.push(n2 - n1);
                } 
                else if(tokens[i] == "*") {
                    ans.push(n2 * n1);
                } 
                else if(tokens[i] == "/") {
                    ans.push(n2 / n1);
                }
            } 
            else {
                
                ans.push(stoi(tokens[i]));
            }
        }
        return ans.top();
    }
};