class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        if(m==1){
            int  maxi=INT_MIN;
            for(auto it :nums){
                maxi=max(maxi,abs(it));
            }
            return 1LL*maxi*maxi;
        }
        int n = nums.size();
        vector<int>maxi(n),mini(n);
        maxi[0]=nums[0];
        mini[0]= nums[0];
        for(int i=1;i<n;i++){
            maxi[i]=max(maxi[i-1],nums[i]);
            mini[i]=min(mini[i-1],nums[i]);
        }
        // int j= m-1;
        // long long ans=-1e15;
        // long long maxi =INT_MIN; long long mini =INT_MAX;
        // if(m==nums.size()) return 1LL*nums[0]*nums[n-1];
        // while(j<n){
        //     if(nums[j]>=0 && maxi !=INT_MIN ){
        //         ans = max(ans, 1LL*maxi*nums[j]);
        //         if(mini!=INT_MAX) ans = max(ans, 1LL*mini*nums[j]);
        //     }
        //     if(nums[j]<0 && mini!=INT_MAX){
        //         ans= max(ans, 1LL*mini*nums[j]);
        //         if(maxi!=INT_MIN) ans=max(ans, 1LL*maxi*nums[j]);
        //     }
        //     int i=j-m+1;
        //     if(nums[i]>=0) maxi=max(maxi,1LL*nums[i]);
        //     else mini=min(mini,1LL*nums[i]);
        //     j++;
        // }
        // return ans;

        int j=m-1;
        long long ans = -1e16;
        while(j<n){
            ans= max(ans, 1LL*maxi[j-m+1]*nums[j]);
            ans = max(ans, 1LL* mini[j-m+1]*nums[j]);
            j++;
        }
        return ans;
        
        
    }
};