class Solution {
public:
    // bool check(vector<int>& nums,vector<vector<int>>&queries,int k){
    //     vector<int>freq(nums.size()+1,0);
    //     for(int i=0;i<k;i++){
    //         freq[queries[i][0]]+=1;
    //         freq[queries[i][1]+1]-=1;
    //     }
    //     for(int i=1;i<freq.size();i++){
    //         freq[i]+=freq[i-1];
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]>freq[i]) return false;
    //     }
    //     return true;
    // }
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // int ans=0;
        // sort(queries.begin(),queries.end(),[](const vector<int> & a,const vector<int>& b){
        //     if(a[0]!=b[0]) return a[0]<b[0];
        //     return a[1]>b[1];
        // });
        // for(int k=queries.size();k>0;k--){
        //     if(!check(nums,queries,k)) break;
        //     ans++;
        // }
        // return ans-1;


        // sort(queries.begin(),queries.end(),[](const vector<int> & a,const vector<int>& b){
        //     if(a[0]!=b[0]) return a[0]<b[0];
        //     return a[1]>b[1];
        // });
        // vector<vector<int>>dup;
        // int k=0;
        // if(!check(nums,queries,queries.size())) return -1;
        // for(int i=0;i<nums.size();i++){
        //     int n =nums[i];
        //     if(n==0) continue;
        //     for(int j=k;j<queries.size();j++){
        //         if(queries[j][0]==i){
        //             dup.push_back({queries[j][0],queries[j][1]});
        //             n--;
        //         }
        //         k++;
        //         if(n==0) break;
        //     }
        // }
        // int ans=0;
        // for(int i=dup.size();i>0;i--){
        //     if(!check(nums,dup,i)) break;
        //     ans++;
        // }
        // return queries.size()-dup.size()+ans-1;

        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>used;
        priority_queue<int>available;
        sort(queries.begin(),queries.end());
        int cnt=0;
        int pos=0;
        for(int i=0;i<n;i++){
            while(pos<queries.size() && queries[pos][0]==i){
                available.push(queries[pos][1]);
                pos++;
            }
            nums[i]-=used.size();
            while(nums[i]>0 && !available.empty() && available.top()>=i){
                used.push(available.top());
                available.pop();
                nums[i]--;
                cnt++;
            }
            if(nums[i]>0) return -1;
            while(!used.empty() && used.top()==i) used.pop();


        }
        return queries.size()-cnt;




    }
};