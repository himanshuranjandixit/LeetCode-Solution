class Solution {
public:
    int binary2decimal(string& s){
        int ans=0;
        int count=0;
        for(int i=s.size()-1;i>=0;i--){
            ans+=(1<<count)*(s[i]-'0');
            count++;
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        vector<string>v;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            string s="";
            string ss="";
            for(int j=0 ;j<grid[0].size();j++){
                s+=(grid[i][j]+'0');
                ss+=(grid[i][j]^1 + '0');
            }
            int num = binary2decimal(s);
            int num1 = binary2decimal(ss);
            if(num1>num){
                for(int j=0 ;j<grid[0].size();j++){
                    grid[i][j]=ss[j] - '0';
                
                }
                v.push_back(ss);
                ans+=num1;
            }
            else{
                v.push_back(s);
                ans+=num;
            }
        }
        for(int i=grid[0].size()-1;i>=0;i--){
            int sum=0;
            for(auto it:v){
                string s=it;
                s[i] = ((it[i] - '0') ^ 1) + '0';
                sum+=binary2decimal(s);
            }
            if(sum>ans){
                ans=sum;
                for(auto &it:v){
                    it[i] = (it[i]-'0')^(1) + '0';
                }

            } 
        }
        return ans;


        
    }
};