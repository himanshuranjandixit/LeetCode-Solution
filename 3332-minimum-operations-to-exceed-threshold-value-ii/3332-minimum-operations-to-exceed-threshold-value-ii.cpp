class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        bool yes=true;
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        while(yes){
            if(pq.top()>=k){
                yes=false;
                continue;
            }
            count++;
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            long long val =min(x,y)*2;
            val+=max(x,y);
            pq.push(val);
        }
        return count;
        
    }
};