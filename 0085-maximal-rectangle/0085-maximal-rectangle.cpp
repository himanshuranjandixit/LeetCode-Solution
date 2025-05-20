class Solution {
public:
    int solve(vector<int>& mat){
        stack<int>st1;
        stack<int>st2;
        vector<int>prev(mat.size(),0);
        vector<int>next(mat.size(),0);
        int ans=0;
        for(int i=0;i<mat.size();i++){
            int pse=-1;
            while(!st1.empty() && mat[st1.top()]>=mat[i]){
                st1.pop();
            }
            if(!st1.empty()) pse=st1.top();
            st1.push(i);
            prev[i]=pse;
        }
        for(int i=mat.size()-1;i>=0;i--){
            int nse=mat.size();
            while(!st2.empty() && mat[st2.top()]>=mat[i]) st2.pop();
            if(!st2.empty()) nse = st2.top();
            st2.push(i);
            next[i]=nse;
        }
        for(int i=0;i<prev.size();i++){
            int length= next[i]-prev[i]-1;
            ans=max(ans,length*mat[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix[0].size();i++){
            int count=0;
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]=='1') count++;
                else count=0;
                mat[j][i]=count;
            }
        }int ans=0;
        for(int i=0;i<mat.size();i++){
            ans=max(ans,solve(mat[i]));

        }
        return ans;
    }
};