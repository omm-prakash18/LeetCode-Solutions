#include <stack>
#include <utility>   // For std::pair
#include <algorithm> // For std::min

class MinStack {
private:
    // Stack stores pairs: {value, current_minimum}
    std::stack<std::pair<int, int>> st;

public:
    // Constructor
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            // If empty, the first value is also the minimum
            st.push({val, val});
        } else {
            // Calculate new minimum and push the pair
            int current_min = st.top().second;
            st.push({val, std::min(val, current_min)});
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        // .first gives access to the actual value
        return st.top().first;
    }
    
    int getMin() {
        // .second gives access to the stored minimum
        return st.top().second;
    }
};