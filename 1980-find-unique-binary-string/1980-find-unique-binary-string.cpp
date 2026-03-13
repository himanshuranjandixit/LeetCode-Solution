class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums[0].size();    //000   001  010 011 
    
        int numm =0;
        for(int i=0;i<nums.size();i++){
            string temp = nums[i];
            int num=0;
            for(int j =0;j<temp.size();j++){
                num += (temp[temp.size()-j-1] =='0' ? 0 : (int)pow(2,j));
            }
            if(numm != num){
                string ans= bitset<32>(numm).to_string();
                ans = ans.substr(32-n);
                return ans;
            }
            numm++;

        }
        string ans= bitset<32>(numm).to_string();
        ans = ans.substr(32-n);
        return ans;
    }
};