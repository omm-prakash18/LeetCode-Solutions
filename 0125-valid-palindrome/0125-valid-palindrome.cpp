class Solution {
public:
    bool isPalindrome(string s) 
    {
        string a = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z') {
                a += s[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z') {
                a += s[i] + 32;
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                a += s[i];
            }
        }
        
        for(int i = 0, j = a.length() - 1; i < j; i++, j--)
        {
            if(a[i] != a[j]) 
            {
                return false;
            }
        }
        return true;
    }
};