class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        while(numRows--){
            vector<int>temp;
            temp.push_back(1);
            if(ans.size()==0){
                ans.push_back(temp);
                continue;
            }
            for(int i=0;i<ans[ans.size()-1].size()-1;i++){
                int add = ans[ans.size()-1][i]+ans[ans.size()-1][i+1];
                temp.push_back(add);
            }
            temp.push_back(1);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
        
    }
};