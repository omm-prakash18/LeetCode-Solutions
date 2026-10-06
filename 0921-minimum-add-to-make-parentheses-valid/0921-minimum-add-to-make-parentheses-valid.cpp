class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;    
        int additionsNeeded = 0;  
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
             
                openBrackets++; 
            } 
            else {
               
                if (openBrackets > 0) {
                   
                    openBrackets--; 
                } else {
                   
                    additionsNeeded++; 
                }
            }
        }
        
       
        return additionsNeeded + openBrackets;
    }
};