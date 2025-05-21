class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int ans=0;
        int l=0;
        int r=0;
        while(r<fruits.size()){
            mpp[fruits[r]]=r;
            if(mpp.size()>2){
                int indx=INT_MAX;
                for(auto it:mpp){
                    indx=min(indx,it.second);
                }
                mpp.erase(fruits[indx]);
                l=indx+1;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;

        
    }
};