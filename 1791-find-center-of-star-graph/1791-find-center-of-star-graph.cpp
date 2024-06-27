class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ans1 = edges[0][0] ;
        int ans2 = edges[0][1] ;
        if(ans1 == edges[1][0] || ans1 == edges[1][1]) return ans1;
        return ans2 ;

        
    }
};