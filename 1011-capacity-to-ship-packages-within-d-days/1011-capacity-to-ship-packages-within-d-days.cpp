class Solution {
private:
   
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;
        int currentLoad = 0;
        
        for (int i = 0; i < weights.size(); i++) {
            if (currentLoad + weights[i] > capacity) {
               
                daysNeeded++;
                currentLoad = weights[i];
            } else {
                currentLoad += weights[i];
            }
        }
        return daysNeeded <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(), weights.end());
        
        
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        int high = sum; 
        while (low < high) {
            int mid = low + ((high - low) / 2);
            
            if (canShip(weights, days, mid)) {

                high = mid;
            } else {
            
                low = mid + 1;
            }
        }
        
        return low; 
    }
};