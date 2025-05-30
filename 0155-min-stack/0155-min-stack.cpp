class MinStack {
public:
    stack<pair<int,long>>st;
    long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini=min(mini,(long)val);
        st.push({val,mini});
        
    }
    
    void pop() {
        auto x=st.top();
        st.pop();
        if(st.empty()) mini=INT_MAX;
        if(mini==x.second)mini=st.top().second;
        
        
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return (int)st.top().second;
        
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