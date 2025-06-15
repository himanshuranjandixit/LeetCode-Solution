class Solution {
public:
    int maxDiff(int num) {
        if(num==0) return 9;
        string nums =to_string(num);
        unordered_map<char,char>mpp1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!='9' && mpp1.find(nums[i])==mpp1.end()&& mpp1.size()<1){
                mpp1[nums[i]]='9';
            }
        }
        unordered_map<char,char>mpp2;
        if(nums[0]!='1') mpp2[nums[0]]='1';
        for(int i=1;i<nums.size();i++){
            if(nums[0]=='1' && nums[i]=='1') continue;
            if(i!=0 && nums[i]!='0' && mpp2.find(nums[i])==mpp2.end()&& mpp2.size()<1){
                mpp2[nums[i]]='0';
            }

        }
        string maxi="";
        string mini="";
        for(int i=0;i<nums.size();i++){
            if(mpp1.find(nums[i])!=mpp1.end()) maxi+=mpp1[nums[i]];
            else maxi+=nums[i];
            if(mpp2.find(nums[i])!=mpp2.end()) mini +=mpp2[nums[i]];
            else mini+=nums[i];
        }
        return stoi(maxi)-stoi(mini);
    }
};