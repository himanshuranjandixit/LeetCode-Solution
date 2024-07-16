class Solution {
public:
    vector<int>jadoo(int n){
        vector<int>v(1);
        return v;
    }
    vector<vector<int>> fourSum(vector<int>& nums,int target) {

        // time complexity ----->> O(N^2)   Brute force approach



        // vector<vector<int>>ans;
        // set<vector<int>>v;
        // sort(nums.begin(),nums.end());
        // int sum=0;
        // if(nums.size()<4 || nums[0]>target && target>=0) jadoo(nums.size());
        // else{
        //     for(int i=0;i<nums.size()-3;i++){
        //         for(int j=i+1;j<nums.size()-2;j++){
        //             for(int k=j+1;k<nums.size()-1;k++){
        //                 for(int l=k+1;l<nums.size();l++){
        //                     long long chh= nums[i]+nums[j];
        //                     chh+=nums[k];
        //                     chh+=nums[l];
        //                     if(chh == target){
        //                         v.insert({nums[i],nums[j],nums[k],nums[l]});
        //                     }
        //                     else if(chh > target){
        //                         break;
        //                     }
        //                 }

        //             }
        //         }
        //     }
        //     for(auto it:v){
        //         ans.push_back(it);
        //     }
        //     return ans ;
        // }
        // return ans;

        // time complexity ----->>>O(N^3)   Optimize approach 

        vector<vector<int>>ans;
        set<vector<int>>v;
        sort(nums.begin(),nums.end());
        int sum=0;
        if(nums.size()<4 || nums[0]>target && target>=0) jadoo(nums.size());
        else{
            for(int i=0;i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    set<long long>hash;
                    for(int k=j+1;k<nums.size();k++){
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        long long fourth = target-(sum);
                        if(hash.find(fourth) != hash.end()){
                            v.insert({nums[i],nums[j],nums[k],(int)fourth});
                        }
                        hash.insert(nums[k]);

                    }
                }
            }
            for(auto it:v){
                ans.push_back(it);
            }
            return ans ;
        }
        return ans;
        
    }
};