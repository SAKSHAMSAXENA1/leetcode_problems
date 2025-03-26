class MinStack {
public:
stack<long> st;
long mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            mini=val;
        }
        else if(val<mini)
        {
            st.push(2*(long)val-mini);
            mini=val;
        }
        else // mini<val
        {
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top()<mini) // modified val was pushed into stack
        {
            int x=st.top();
            mini=2*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        return max(st.top(),mini);
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */