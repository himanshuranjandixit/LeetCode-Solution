class Solution {
public:
    int solve(vector<int>& v) {
        int cons = 0;
        int subCount = 0;
        for(auto it : v) {
            if(it == 0) cons = 0;
            else cons++;
            subCount += cons;
        }
        return subCount;
    }
    int numSubmat(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        for(int i = 0;i < m;i++) {
            vector<int> v(n, 1);
            for(int j =i;j < m;j++){
                for(int k = 0; k < n;k++) v[k] = v[k] & mat[j][k];
                result += solve(v);
            }
        }
        return result;
    }
};