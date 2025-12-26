class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>pref(n+1);
        int sum=0;
        for(auto it:customers){
            if(it=='Y') sum++;
        }
        int y=0;
        int N=0;
        for(int i=0;i<n;i++){
            pref[i]=sum-y+N;
            if(customers[i]=='Y') y++;
            else N++;
        }
        pref[n]=sum-y+N;
        int penalty=INT_MAX;
        int ans= -1;
        for(int i=0;i<n+1;i++){
            if(penalty>pref[i]){
                penalty=pref[i];
                ans=i;
            }

        }
        return ans;
    }
};