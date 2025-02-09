class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        int maxi=INT_MIN;
        for(auto it1 :mpp){
            int odd;
            if(it1.second%2!=0){
                odd=it1.second;
                for(auto it2 :mpp){
                    if(it2.second%2==0){
                        int even=it2.second;
                        maxi=max(maxi,odd-even);
                    }
                }
            }
        }
        return maxi;
        
    }
};