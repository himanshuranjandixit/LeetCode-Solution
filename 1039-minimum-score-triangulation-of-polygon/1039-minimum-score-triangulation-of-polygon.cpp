class Solution {
public:
    int t[51][51];
    int solve(vector<int>& values, int i, int j){
        if(j-i+1<3) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int res =INT_MAX;
        for(int k=i+1;k<j;k++){
            int val = solve(values,i,k)+ values[i]*values[j]*values[k] + solve(values,k,j);
            res=min(res,val);
        }
        return t[i][j]= res;

    }
    int minScoreTriangulation(vector<int>& values) {
        memset(t,-1,sizeof(t));
        return solve(values,0,values.size()-1);

        
    }
};                                                                             