class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ans;
        int n = operations.size();
        
        for(int i = 0; i < n; i++) {
            if (operations[i] == "+") {
                
                int top1 = ans.top(); 
                ans.pop();
                int top2 = ans.top();
                
                
                ans.push(top1);
                ans.push(top1 + top2);
            } 
            else if (operations[i] == "D") { 
                ans.push(ans.top() * 2);
            } 
            else if (operations[i] == "C") {
                
                ans.pop();
            } 
            else {
                
                ans.push(stoi(operations[i]));
            }
        }
        
        int sum = 0;
        while (!ans.empty()) {
            sum += ans.top();
            ans.pop();
        }
        
        return sum;
    }
};