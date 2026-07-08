class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            if (val < st.top().second) {
                st.push({val, val});
            } else {
                st.push({val, st.top().second});
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        st.pop();
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.top().first;
    }
    
    int getMin() {
        if (st.empty()) return -1;
        return st.top().second;
    }
};