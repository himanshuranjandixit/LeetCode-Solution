class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<>>pq;
        pq.push(1);
        set<long>st;
        st.insert(1);
        vector<int>ugly ={2,3,5};
        long val;
        for(int i=1;i<=n;i++){
            val = pq.top();
            pq.pop();
            for(int j=0;j<3;j++){
                long value  = ugly[j]*val;
                if(st.count(value)==0){
                    pq.push(value);
                    st.insert(value);
                }

            }

        }
        return int(val);
        
    }
};