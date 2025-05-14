class Solution {
public:
    int M=1e9+7;
    vector<vector<int>> mul(vector<vector<int>>t1, vector<vector<int>>t2){
        vector<vector<int>>res(26,vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
               for(int k=0;k<26;k++){
                res[i][j]=(res[i][j]+1LL*t1[i][k]*t2[k][j]%M)%M;
               }
            }
        }
        return res;
    }
    vector<vector<int>> fastexp(vector<vector<int>> T, int t){
        if(t==1) return T;
        vector<vector<int>>resultby2 = fastexp(T,t/2);
        vector<vector<int>>result = mul(resultby2,resultby2);
        if(t&1) return mul(result,T);
        else return result;

    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // vector<int>mp(26,0);
        // for(int i=0;i<s.size();i++){
        //     mp[s[i]-'a']++;
        // }
        // while(t--){
        //     vector<int>temp(26,0);
        //     for(int i=0;i<26;i++){
        //         int freq=nums[i];
        //         for(int j=1;j<=freq;j++){
        //             temp[(i+j)%26]=(temp[(i+j)%26]+mp[i])%M;
        //         }
        //     }
        //     mp=move(temp);
        // }
        // int ans=0;
        // for(int i=0;i<26;i++){
        //     ans=(ans+mp[i])%M;
        // }
        // return ans;

        vector<int>fq(26,0);
        for(int i=0;i<s.size();i++){
            fq[s[i]-'a']++;
        }
        vector<vector<int>>T(26,vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int j=1;j<=nums[i];j++){
                T[i][(i+j)%26]++;
            }
        }
        vector<vector<int>> Tt= fastexp(T,t);
        vector<int>ansfq(26,0);
        for(int i=0;i<26;i++){
            if(fq[i]==0) continue;
            for(int j=0;j<26;j++){
                ansfq[i]=(ansfq[i]+1LL*Tt[i][j]*fq[i]%M)%M;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+ansfq[i])%M;
        }
        return ans;
    }
};