class MinStack {
public:
    stack<int> st;
    stack<int> mins;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        int mini = min(val, (!mins.empty()) ? mins.top(): val);
        mins.push(mini);
    }
    
    void pop() {
        mins.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
