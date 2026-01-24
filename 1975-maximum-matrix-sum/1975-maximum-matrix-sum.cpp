class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        int el=INT_MAX;
        long long sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                el=min(el,abs(matrix[i][j]));
                if(matrix[i][j]<0) count++;
                sum+=abs(matrix[i][j]);
            }
        }
        cout<<sum;
        if(count%2) return sum-2*el;
        return sum;
    }
};