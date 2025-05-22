class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // pair<int,int>maxi={INT_MIN,-1};
        // for(int i=0;i<k;i++){
        //     if(maxi.first<nums[i]){
        //         maxi={nums[i],i};
        //     }
        // }
        // vector<int>ans;
        // pair<int,int>temp={INT_MIN,-1};
        // int j=0;
        // ans.push_back(maxi.first);
        // for(int i=k;i<nums.size();i++){
        //     j=i-k+1;
        //     int maxx;
        //     if(nums[i]>temp.first){
        //         temp={nums[i],i};
        //     }
        //     if(maxi.second<j){
        //         maxx=temp.first;
        //         maxi=temp;
        //         temp={INT_MIN,-1};
        //     }
        //     else if(nums[i]>maxi.first){
        //         maxi={nums[i],i};
        //         temp={INT_MIN,-1};
        //     }
        //     ans.push_back(maxi.first);
        // }
        // return ans;
        
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        int j=0;
        vector<int>ans;
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            int j=i-k+1;
            if(pq.top().second<j){
                pq.pop();
            }
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<j){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};