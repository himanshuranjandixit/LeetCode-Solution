class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_map<string,bool>mpp;
        vector<string>ans;
        for(auto it : folder){
            string subfolder ="";
            bool check=true;
            for(int i=0;i<it.size();i++){
                if(!subfolder.empty() && it[i]=='/'){
                    if(mpp.count(subfolder)){
                        check =false;
                        break;
                    }
                }
                subfolder+=it[i];
            }
            if(check){
                mpp[subfolder]=true;
                ans.push_back(subfolder);
            }
        }
        return ans;
        
    }
};