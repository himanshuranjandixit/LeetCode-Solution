class FreqStack {
public:
    stack<pair<int, int>> st; // {value, frequency}
    unordered_map<int, int> mpp; // value -> frequency
    FreqStack() {

    }
    void push(int val) {
        mpp[val]++;
        st.push({val, mpp[val]});
    }
    int pop() {
    //     int val=st.top().first;
    //     int freq=st.top().second;
        int maxi=INT_MIN;
        stack<pair<int,int>>temp;
        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }
        while(!st.empty()){
            if(st.top().second!=maxi){
                temp.push(st.top());
                st.pop();
            } 
            else{
                mpp[st.top().first]--;
                int val=st.top().first;
                st.pop();
                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }
                return val;
            }

        }
        return 0;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */