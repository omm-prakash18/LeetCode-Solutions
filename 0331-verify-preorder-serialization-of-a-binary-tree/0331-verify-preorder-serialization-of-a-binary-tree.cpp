class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot =1;
        vector<string> result;
        stringstream ss(preorder);
        string item;
    
    
        while (getline(ss, item, ',')) {
            result.push_back(item);
        }
        for(int i=0;i<result.size();i++)
        {
            if(slot<=0 )
                return false;
            if(result[i] == "#")
            {
                slot =slot-1;
            }
            else
            {
                slot +=1;
            }
        }
    
    return (slot==0);
    }
};