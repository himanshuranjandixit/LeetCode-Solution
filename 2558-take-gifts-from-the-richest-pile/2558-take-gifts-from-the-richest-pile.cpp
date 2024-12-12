class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        for(int i=0;i<k;i++){
            sort(gifts.begin(),gifts.end(),greater<int>());
            gifts[0]=floor(sqrt(gifts[0]));
        }
        for(int i=0;i<gifts.size();i++){
            ans+=gifts[i];
        }
        return ans;
        
    }
};