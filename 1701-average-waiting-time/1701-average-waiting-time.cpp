class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        double sum = customers[0][0];
        for(int i = 0 ; i<customers.size() ; i++){
            if(sum<customers[i][0]){
                ans+=customers[i][1];
                sum = customers[i][0] + customers[i][1];
                continue;
                
            }
            sum += customers[i][1];
            ans+= sum-customers[i][0];

        }
        ans = ans/customers.size();
        return ans;
        
    }
};