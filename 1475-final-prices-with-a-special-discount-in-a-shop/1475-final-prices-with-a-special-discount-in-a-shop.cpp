class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        for(int i=0;i<prices.size()-1;i++){
            int discount=0;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=prices[i]){
                    discount=prices[j];
                    break;
                }
            }
            ans.push_back(prices[i]-discount);
        }
        ans.push_back(prices[prices.size()-1]);
        return ans;
        
    }
};