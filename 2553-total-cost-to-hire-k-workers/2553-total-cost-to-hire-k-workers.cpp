class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        int l= 0;
        int r=n-1;
        priority_queue<int,vector<int>,greater<>>left,right;
        while(left.size()<candidates && l<r){
            left.push(costs[l]);
            l++;
        }
        while(right.size()<candidates && r>=l){
            right.push(costs[r]);
            r--;
        }

        long long ans = 0;
        while(k--){
            if(right.empty() || (!left.empty() && left.top()<=right.top())){
                ans += left.top(); left.pop();
                if(l<=r){
                    left.push(costs[l]);
                    l++;
                }
            }
            else{
                ans+=right.top();
                right.pop();
                if(l<=r) right.push(costs[r--]);
            }
        }

        return ans;
    }
};
