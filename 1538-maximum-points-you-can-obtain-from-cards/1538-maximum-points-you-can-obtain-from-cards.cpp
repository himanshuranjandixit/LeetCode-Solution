class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>st(cardPoints.size(),0);
        vector<int>end(cardPoints.size(),0);
        st[0]=cardPoints[0];
        end[cardPoints.size()-1]=cardPoints[cardPoints.size()-1];
        for(int i=1;i<cardPoints.size();i++) st[i]=cardPoints[i]+st[i-1];
        for(int i=cardPoints.size()-2;i>=0;i--) end[i]=cardPoints[i] + end[i+1];
        int ans=0;
        int j;
        int startsum=0;
        int endsum=0;
        if(k>=st.size()) return st[st.size()-1];
        for(int i=0;i<=k;i++){
            if(i>0) startsum=st[i-1];
            else startsum=0;
            if(k-i>0) endsum=end[st.size()-k+i];
            else endsum=0;
            ans=max(ans,startsum+endsum);
        }
        return ans;

        
        
        
    }
};