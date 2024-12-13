class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        vector<int>mark(nums.size()+2);
        bool check=true;
        while(check){
            int smallest=INT_MAX;
            check=false;
            int indx=-1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<smallest && mark[i]==0){
                    smallest=nums[i];
                    indx=i;
                    check=true;
                }
            }
            if(indx==-1) continue;
            if(indx==0) mark[1]=1;
            else if (indx==nums.size()-1) mark[nums.size()-2]=1;
            else{ 
                mark[indx-1]=1;
                mark[indx+1]=1;
            }
            mark[indx]=1;
            score+=nums[indx];

        }
        return score;

        
    }
};