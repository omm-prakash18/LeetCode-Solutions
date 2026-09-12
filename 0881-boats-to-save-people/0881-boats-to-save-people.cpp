class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int count =0;
        int n = people.size();
        sort(people.begin(),people.end());
        int left =0;
        int right =people.size()-1;
        while(left <= right)
        {
            if(people[left] + people[right]<=limit)
            {
                count ++;
                left ++;
                right --;
            }
            else
            {
                count++;
                right--;
            }
        }

        return count;
    }
};
//another important question