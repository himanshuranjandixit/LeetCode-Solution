class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long ans=0;
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            ans+=piles[i];
            maxi=max(maxi,piles[i]);
        }
        int ansi=ans/h;
        if(ans%h!=0) ansi++;
        ans=ansi;
        // int mini=0;
        // for(int i=ans;i<=maxi;i++){
        //     int val=0;
        //     for(int j=0;j<piles.size();j++){
        //         val+=piles[j]/i;
        //         if(piles[j]%i!=0)val++;
        //     }
        //     if(val<=h){
        //         mini=i;
        //         break;
        //     }
        // }
        // return mini;
        int low = ans;
        int high = maxi;
        while(low<high){
            int mid = (low+high)/2;
            int val = 0;
            for(int i=0;i<piles.size();i++){
                val+=piles[i]/mid;
                if(piles[i]%mid!=0) val++;
        
            }
            if(val<=h) high=mid;
            else low=mid+1;

        }
        return low;

        
    }
};