class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<elements.size();i++){
            if(mpp.find(elements[i])==mpp.end()) mpp[elements[i]]=i;
        }
        for(int i=0;i<groups.size();i++){
            int k=INT_MAX;
            for(int j=1;j*j<=groups[i];j++){
                if(groups[i]%j==0 && mpp.find(j)!=mpp.end()) k=min(k,mpp[j]);
                if(groups[i]%j==0 && mpp.find(groups[i]/j)!=mpp.end()) k=min(k,mpp[groups[i]/j]);
            }
            if(k==INT_MAX) ans.push_back(-1);
            else ans.push_back(k);
        }
        return ans;
        
    }
};